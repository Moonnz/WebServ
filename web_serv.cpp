//
// Created by root on 04/09/18.
//

#include "web_serv.h"

web_serv::~web_serv() {
    stop();
    #if defined(WIN32)
        WSACleanup();
    #endif
}

int web_serv::stop(){
    this->b.stop_serv = true;
    while(b.stopped != true){
        std::cout << "waiting for stop" << std::endl;
        sleep(1);
    }
    this->serv_thread->join();
    return 0;
}

web_serv::web_serv() {
    int erreur = 0;
    #if defined(WIN32)
    WSADATA WSAData;
    int erreur = WSAStartup(MAKEWORD(2,2), &WSAData);
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
        std::this_thread::sleep_for(std::chrono::milliseconds(50));
    }
}

void web_serv::thread_core_function(void *args){
    container *for_here = (container*)args; // Je récupére la structure
    SOCKET socket_local = 0;
    unsigned char buffer_local[__BUFFER_SIZE];
    memset(buffer_local, 0, __BUFFER_SIZE);
    std::string request;
    bool boolean = false;

    char crlf[4] = {13,10,13,10};

    while(1){ //Je lance la boucle infini
        for_here->mut.lock(); // Je verrouille la strucutre.
        if(for_here->socket_list.size() > 0){
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
        if(socket_local != 0){
            boolean = false;
            while(!boolean) {
                int rec = recv( socket_local, (char *)buffer_local, __BUFFER_SIZE, 0 );
                if(rec == -1){
                    boolean = true;
                    #if defined(WIN32)
                    std::cout << WSAGetLastError() << std::endl;
                    #endif
                }
                request.append(reinterpret_cast<char *>(buffer_local));
                for(int i = 0; i < __BUFFER_SIZE-3; i++){
                    if(buffer_local[i] == 13 && buffer_local[i+1] == 10 && buffer_local[i+2] == 13 && buffer_local[i+3] == 10){
                        boolean = true;
                        break;
                    }
                }
                memset(buffer_local, 0, __BUFFER_SIZE);
                if(boolean)
                    break;
            }
            std::vector<std::string> azerty = request_response::cut_by(request, "\r\n");
            std::string body = "<html><body>0</body></html>";
            std::string head;
            head.append("HTTP/1.1 200 OK\r\nContent-Length: ");
            head.append(std::to_string(body.length()));
            head.append("\r\nContent-type: text/html\r\nConnection: Closed\r\n\r\n");
            std::string a;
            a.append(head.c_str()).append(body.c_str());
            request_response *req_resp = new request_response(request);

            if(send(socket_local, a.c_str(), a.length(), 0) == -1){
                #if defined(WIN32)
                std::cout << WSAGetLastError() << std::endl;
                #elif defined(linux)
                std::cout << errno << std::endl;
                #endif

            }
            close(socket_local);
            socket_local = 0;
        }
        std::this_thread::sleep_for(std::chrono::milliseconds(1000));
    }
}