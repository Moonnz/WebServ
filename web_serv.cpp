//
// Created by root on 04/09/18.
//

#include "web_serv.h"

web_serv::~web_serv() {
    std::cout << "destructor call" << std::endl;
    stop();
    #if defined(WIN32)
        WSACleanup();
    #endif
}

int web_serv::stop(){
    std::cout << "stop call" << std::endl;
    this->b.stop_serv = true;
    while(b.stopped != true){        
    }
    this->serv_thread->join();
    return 0;
}

web_serv::web_serv() {
    int erreur = 0;
    #if defined(WIN32)
    WSADATA WSAData;
    erreur = WSAStartup(MAKEWORD(2,2), &WSAData);
    #endif
    std::cout << erreur << " startup" << std::endl;

    this->a.stop = false;
    recsize = sizeof(sin);
    crecsize = sizeof(csin);

    sock = socket(AF_INET, SOCK_STREAM, 0);
    sin.sin_addr.s_addr = htonl(INADDR_ANY);
    sin.sin_family = AF_INET;
    sin.sin_port = htons(80);
    int optval = 1;
    //setsockopt( sock, SOL_SOCKET, SO_REUSEPORT, &optval, sizeof(optval) );
    setsockopt( sock, SOL_SOCKET, SO_REUSEADDR, (char *)&optval, sizeof(optval) );

    int sock_err = bind(sock, (SOCKADDR*)&sin, recsize);

    if(sock_err == -1){
        std::cout << "bind" << std::endl;
        exit(10);
    }

    sock_err = listen(sock, 5);

    if(sock_err == -1){
        std::cout << "listen" << std::endl;
        exit(11);
    }

    #if defined(linux)
        fcntl(sock, F_SETFL, O_NONBLOCK);
    #elif defined(WIN32)
        ioctlsocket(sock,FIONBIO,(unsigned long *)&optval);
    #endif
        this->b.sock_serv = sock;
        this->b.sock_serv_info = sin;
        this->b.sock_serv_info_size = recsize;
        if(this->a.mut.try_lock())
            this->a.mut.unlock();
    try {
        this->serv_thread = new std::thread( std::thread( serv_core_function, (void *)&this->a, (void *)&this->b ));
    }catch(std::system_error &e){
        std::cout << "Failed: " << e.code() << std::endl;
    }

}

void web_serv::serv_core_function(void *argOne, void *argTwo) {
    container *for_here = (container*)argOne; // Je récupére la structure
    container_serv *serv_for_here = (container_serv*)argTwo;
    for_here->mut.lock();
    for_here->thread_list.resize(__THREAD_NUMBER);
    for_here->mut.unlock();
    std::cout << "serv_thread ok" << std::endl;
    for(int i = 0; i < __THREAD_NUMBER; i++){
        try {
            for_here->thread_list.push_back(std::thread(thread_core_function, argOne));
        }catch (std::system_error &e){
            std::cout << "Many failed: " << e.code() << std::endl;
        }
    }
    std::cout << "serv_thread ok ok" << std::endl;
    while(1){
        serv_for_here->mut.lock();
        if(!serv_for_here->stop_serv){
            SOCKET temp = accept(serv_for_here->sock_serv, (SOCKADDR*)&serv_for_here->sock_serv_info, &serv_for_here->sock_serv_info_size);
            if(temp != -1){
                for_here->mut.lock();
                for_here->socket_list.push_back(temp);
                for_here->mut.unlock();
            }
            serv_for_here->mut.unlock();
        }else{
            serv_for_here->mut.unlock();
            for_here->mut.lock();
            std::cout << "stop thread set to true" << std::endl;
            for_here->stop_thread = true;
            for_here->mut.unlock();
            for(int i = 0; i < __THREAD_NUMBER; i++){
                for_here->thread_list.back().join();
                for_here->thread_list.pop_back();
            }
            serv_for_here->mut.lock();
            serv_for_here->stopped = true;
            serv_for_here->mut.unlock();
            break;
        }
        std::this_thread::sleep_for(std::chrono::milliseconds(1));
    }
}

void web_serv::thread_core_function(void *args){
    container *for_here = (container*)args; // Je récupére la structure
    SOCKET socket_local = 0;
    unsigned char buffer_local[__BUFFER_SIZE];
    memset(buffer_local, 0, __BUFFER_SIZE);
    std::string request;
    bool boolean = false;
    request_response *req_resp = NULL;
    std::chrono::time_point<std::chrono::system_clock> start;
    std::chrono::time_point<std::chrono::system_clock> start_deux;
    bool keep_alive = false;
    bool close_for_timeout = false;
    int rec;

    char crlf[4] = {13,10,13,10};

    while(1){ //Je lance la boucle infini
        memset(buffer_local, 0, __BUFFER_SIZE);
        if(!keep_alive){
            for_here->mut.lock(); // Je verrouille la strucutre.
            if(for_here->socket_list.size() > 0){
                request = "";
                socket_local = for_here->socket_list.back();
                for_here->socket_list.pop_back(); // Et je le supprime de la liste.
            }else{
                socket_local = 0;
            }
    
            if(for_here->stop_thread){ // Je verifie au passage si il faut stoppé le thread.
                std::cout << "thread stop" << std::endl;
                for_here->mut.unlock(); // Et je libere avant d'arréter.
                break; // J'arréte la boucle donc le thread.
            }
    
            for_here->mut.unlock(); // Je dévérouille la structure.
        }
        
        if(socket_local != 0){
            int nb = 0;
            boolean = false;
            while(!boolean) {
                rec = recv( socket_local, (char *)buffer_local, __BUFFER_SIZE, 0 );
                
                if(rec == -1){
                    #if defined(WIN32)
                        if(WSAGetLastError() != 10035)
                            boolean = true;
                    #endif
                }else if(rec > 0){
                    nb++;
                    request.append(reinterpret_cast<char *>(buffer_local));
                    for(int i = 0; i < __BUFFER_SIZE-3; i++){
                        if(buffer_local[i] == 13 && buffer_local[i+1] == 10 && buffer_local[i+2] == 13 && buffer_local[i+3] == 10){
                            boolean = true;
                            break;
                        }
                    }
                    memset(buffer_local, 0, __BUFFER_SIZE);
                }else{
                    boolean = true;
                }
                
                if(boolean)
                    break;
            }
            std::string r;
            if(rec > 0){
                std::cout << "nb: " << nb << std::endl;
                req_resp = new request_response(request);
                request = "";
                char * buf= new char[req_resp->get_response_size()];
                std::cout << "buf size: " << req_resp->get_response_size() << std::endl;
                req_resp->get_response_buf(buf);
                if(send(socket_local, buf, req_resp->get_response_size(), 0) == -1){
                    #if defined(WIN32)
                    std::cout << WSAGetLastError() << std::endl;
                    #elif defined(linux)
                    std::cout << errno << std::endl;
                    #endif
                }
                delete(buf);
                start_deux = std::chrono::system_clock::now();
            }
            
            if(req_resp->keep_alive && !keep_alive){
                        start = std::chrono::system_clock::now();
            }
            keep_alive = req_resp->keep_alive;
            if(keep_alive){
                std::chrono::time_point<std::chrono::system_clock> end = std::chrono::system_clock::now();
                long int diff = std::chrono::duration_cast<std::chrono::nanoseconds>(end-start).count();
                if(diff > 1000000000)
                    close_for_timeout = true;
            }
            
            if(close_for_timeout){
                std::chrono::time_point<std::chrono::system_clock> end_deux = std::chrono::system_clock::now();
                long int diff = std::chrono::duration_cast<std::chrono::nanoseconds>(end_deux-start_deux).count();
                std::cout << "close for timeout with: " << diff << std::endl;
                close(socket_local);
                socket_local = 0;
                delete(req_resp);
                r ="";
                std::cout << "request reset" << std::endl;
                request = "";
                keep_alive = false;
                close_for_timeout = false;
            }else{
                if(!keep_alive || (req_resp != NULL && req_resp->error > 0)){
                    keep_alive = req_resp->keep_alive;
                    if(!keep_alive || (req_resp != NULL && req_resp->error > 0)){
                            close(socket_local);
                            socket_local = 0;
                            delete(req_resp);
                            r ="";
                            std::cout << "request reset DD" << std::endl;
                            request = "";
                            keep_alive = false;
                            close_for_timeout = false;
                    }else{
                        start = std::chrono::system_clock::now();
                        std::cout << "request reset and start set" << std::endl;
                        request = "";
                        delete(req_resp);
                    }
                }
            }
        }
        std::this_thread::sleep_for(std::chrono::milliseconds(1));
    }
}