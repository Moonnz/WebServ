//Include generaux et pour les thread
#include <thread>
#include <mutex>
#include <iostream>
#include <string>
#include <queue>
#include <chrono>

//Include pour le réseaux
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <stdio.h>
#include <stdlib.h>
#include <cstring>
#include <unistd.h>
#include <fcntl.h>

typedef int SOCKET;
typedef struct sockaddr_in SOCKADDR_IN;
typedef struct sockaddr SOCKADDR;

const std::string red("\033[0;31m");
const std::string reset("\033[0m");

//Nombre de thread qui gérerons les connexions.
#define __THREAD_NUMBER 50
//Taille des buffers des threads
#define __BUFFER_SIZE 256

//Structure contenant les données a partager.
//Le mutex doit etres lock avant chaque intervention et unlock apres.
struct container{
    std::vector<std::string> v;
    std::vector<SOCKET> socket_list; // Liste des socket actifs.
    std::mutex mut; // Mutex de sécurité
    bool stop; // Bool a changé pour arréter le serveur
};

//Fonction qui tournera en boucle sur chaque thread.
void core_function(void * args){
    container *for_here = (container*)args; // Je récupére la structure
    SOCKET socket_local;
    unsigned char buffer_local[__BUFFER_SIZE];
    memset(buffer_local, 0, 256);
    ssize_t test;
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
            while( test = recv( socket_local, buffer_local, __BUFFER_SIZE, 0 ) > 0 ) {
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
            send(socket_local, "0", 1, NULL);
            close(socket_local);
            socket_local = 0;
        }

    std::this_thread::sleep_for(std::chrono::milliseconds(1));

    }
}

int main() {
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
    setsockopt( sock, SOL_SOCKET, SO_REUSEPORT, &optval, sizeof(optval) );
    setsockopt( sock, SOL_SOCKET, SO_REUSEADDR, &optval, sizeof(optval) );

    int sock_err = bind(sock, (SOCKADDR*)&sin, recsize);

    if(sock_err == -1)
        exit(10);

    sock_err = listen(sock, 5);

    if(sock_err == -1)
        exit(11);

    fcntl(sock, F_SETFL, O_NONBLOCK);

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

    return 0;
}