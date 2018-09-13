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
#include <fstream>
#include <algorithm>

#include <sys/stat.h>

//Include pour le réseaux
#if defined(linux)
    #include <sys/types.h>
    #include <sys/socket.h>
    #include <netinet/in.h>
    #include <arpa/inet.h>
    #include <unistd.h>
    typedef int SOCKET;
    typedef struct sockaddr_in SOCKADDR_IN;
    typedef struct sockaddr SOCKADDR;
#elif defined(WIN32)
    #include <winsock2.h>
    typedef int socklen_t;
#endif
#include <stdio.h>
#include <stdlib.h>
#include <cstring>
#include <fcntl.h>
#include <unistd.h>
#include <csignal>
//Nombre de thread qui gérerons les connexions.
#define __THREAD_NUMBER 5
//Taille des buffers des threads
#define __BUFFER_SIZE 256
//Chemin vers le dossier contenant les fichiers a envoyer
#if defined(WIN32)
    #define __FILE_PATH "C:\\Users\\Martin\\Documents\\temporaire"
#elif defined(linux)
    #define __FILE_PATH "/home/moonnz/temporaire"
#endif
struct container{
    std::vector<std::thread> thread_list;
    std::vector<SOCKET> socket_list; // Liste des socket actifs.
    bool stop; // Bool a changé pour arréter le serveur
    bool stop_thread = false;
    std::mutex mut; // Mutex de sécurité
};
struct container_serv{
    SOCKET sock_serv;
    SOCKADDR_IN sock_serv_info;
    socklen_t sock_serv_info_size;
    bool stop_serv;
    std::mutex mut;
    bool stopped = false;
};
#endif //THREADTEST_DECL_H
