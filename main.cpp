#include <unistd.h>
#include "web_serv.h"

//Structure contenant les données a partager.
//Le mutex doit etres lock avant chaque intervention et unlock apres.


//Fonction qui tournera en boucle sur chaque thread.
void core_function(void * args){
    container *for_here = (container*)args; // Je récupére la structure
    SOCKET socket_local;
    unsigned char buffer_local[__BUFFER_SIZE];
    memset(buffer_local, 0, 256);
    std::string request;
    bool boolean = false;

    while(1){ //Je lance la boucle infini
        boolean = false;
        for_here->mut.lock(); // Je verrouille la strucutre.

        if(for_here->socket_list.size() > 0){
            socket_local = for_here->socket_list.back();
            for_here->socket_list.pop_back(); // Et je le supprime de la liste.
        }

        if(for_here->stop == true){ // Je verifie au passage si il faut stoppé le thread.
            std::cout << "thread stop" << std::endl;
            for_here->mut.unlock(); // Et je libere avant d'arréter.
            break; // J'arréte la boucle donc le thread.
        }

        for_here->mut.unlock(); // Je dévérouille la structure.
        if(socket_local != 0){
            while( recv( socket_local, (char *)buffer_local, sizeof(buffer_local), 0 ) > 0 ) {
                request.append(reinterpret_cast<char *>(buffer_local));
                for(int i = 0; i < __BUFFER_SIZE-3; i++)
                    if(buffer_local[i] == 13 && buffer_local[i+1] == 10 && buffer_local[i+2] == 13 && buffer_local[i+3] == 10){
                        std::cout << "TRIGGERED" << std::endl;
                        boolean = true;
                        break;
                    }
                if(boolean)
                    break;
                memset(buffer_local, 0, 256);
            }
            std::cout << request << std::endl;
            send(socket_local, "0", 1, 0);
            close(socket_local);
            socket_local = 0;
        }

    std::this_thread::sleep_for(std::chrono::milliseconds(1));

    }
}

int main() {
    web_serv *aze = new web_serv();;
    std::cout << "Server start\n Enter anything to stop" << std::endl;
    int a;
    std::cin >> a;
    aze->stop();
    /*#if defined(WIN32)
        WSADATA WSAData;
        int erreur = WSAStartup(MAKEWORD(2,2), &WSAData);
    #endif
    //Déclaration des variables
    std::vector<std::thread> thread_list;
    container a;
    a.stop = false;

    //INFORMATION SERVEUR
    SOCKADDR_IN sin;
    SOCKET sock;
    socklen_t recsize = sizeof(sin);

    //INFORMATION SOCKET TEMP
    SOCKADDR_IN csin;
    SOCKET csock;
    socklen_t crecsize = sizeof(csin);

    thread_list.resize(__THREAD_NUMBER);
    for(int i = 0; i < __THREAD_NUMBER; i++){
        thread_list.push_back(std::thread(core_function, (void *)&a));
    }

    sock = socket(AF_INET, SOCK_STREAM, 0);
    sin.sin_addr.s_addr = htonl(INADDR_ANY);
    sin.sin_family = AF_INET;
    sin.sin_port = htons(80);
    int optval = 1;
    //setsockopt( sock, SOL_SOCKET, SO_REUSEPORT, &optval, sizeof(optval) );
    setsockopt( sock, SOL_SOCKET, SO_REUSEADDR, (char*)&optval, sizeof(optval) );

    int sock_err = bind(sock, (SOCKADDR*)&sin, recsize);

    if(sock_err == -1)
        exit(10);

    sock_err = listen(sock, 5);

    if(sock_err == -1)
        exit(11);

    #if defined(linux)
        fcntl(sock, F_SETFL, O_NONBLOCK);
    #elif defined(WIN32)
        ioctlsocket(sock,FIONBIO,(unsigned long *)&optval);
    #endif
    while(1){
        SOCKET temp = accept(sock, (SOCKADDR*)&csin, &crecsize);
        if(temp != -1){
            a.mut.lock();
            a.socket_list.push_back(temp);
            a.mut.unlock();
        }else{
            std::this_thread::sleep_for(std::chrono::milliseconds(10));
            std::cout << "sock = -1" << std::endl;
        }
    }

    //
    for(int i = 0; i < __THREAD_NUMBER; i++){
        thread_list.back().join();
        thread_list.pop_back();
    }
    #if defined(WIN32)
        WSACleanup();
    #endif*/

    return 0;
}