//
// Created by root on 05/09/18.
//

#ifndef THREADTEST_DECL_H
#define THREADTEST_DECL_H

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

//Nombre de thread qui gérerons les connexions.
#define __THREAD_NUMBER 50
//Taille des buffers des threads
#define __BUFFER_SIZE 256
typedef int SOCKET;
typedef struct sockaddr_in SOCKADDR_IN;
typedef struct sockaddr SOCKADDR;


struct container{
    std::vector<std::thread> thread_list;
    std::vector<SOCKET> socket_list; // Liste des socket actifs.
    bool stop; // Bool a changé pour arréter le serveur
    bool stop_thread;
    std::mutex mut; // Mutex de sécurité
};
struct container_serv{
    SOCKET sock_serv;
    SOCKADDR_IN sock_serv_info;
    socklen_t sock_serv_info_size;
    bool stop_serv;
    std::mutex mut;
};
#endif //THREADTEST_DECL_H
