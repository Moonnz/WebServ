//
// Created by root on 04/09/18.
//

#ifndef THREADTEST_WEB_SERV_H
#define THREADTEST_WEB_SERV_H

#include "decl.h"

class web_serv {
    public:
        web_serv();
        ~web_serv();
        int stop();
    private:
        //Déclaration des variables
        container a;
        container_serv b;

        std::thread *serv_thread;

        SOCKADDR_IN sin, csin;
        SOCKET sock, csock;
        socklen_t recsize, crecsize;
        int optvalYes;
        int sock_err;

        /*static void thread_core_function(void * args){
        container *for_here = (container*)args; // Je récupére la structure
        SOCKET socket_local;
        unsigned char buffer_local[__BUFFER_SIZE];
        memset(buffer_local, 0, __BUFFER_SIZE);
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
                while( test = recv( socket_local, (char *)buffer_local, __BUFFER_SIZE, 0 ) > 0 ) {
                    request.append(reinterpret_cast<char *>(buffer_local));
                    for(int i = 0; i < __BUFFER_SIZE-3; i++)
                        if(buffer_local[i] == 13 && buffer_local[i+1] == 10 && buffer_local[i+2] == 13 && buffer_local[i+3] == 10){
                            std::cout << "TRIGGERED" << std::endl;
                            boolean = true;
                            break;
                        }
                    if(boolean)
                        break;
                    memset(buffer_local, 0, __BUFFER_SIZE);
                }
                std::cout << request << std::endl;
                send(socket_local, "0", 1, 0);
                close(socket_local);
                socket_local = 0;
            }else{
                std::this_thread::sleep_for(std::chrono::milliseconds(1));
            }
        }
    }
        static void serv_core_function(void * argOne, void * argTwo){
        container *for_here = (container*)argOne; // Je récupére la structure
        container_serv *serv_for_here = (container_serv*)argTwo;
        for_here->mut.lock();
        for_here->thread_list.resize(__THREAD_NUMBER);
        for_here->mut.unlock();
        for(int i = 0; i < __THREAD_NUMBER; i++){
            for_here->thread_list.push_back(std::thread(thread_core_function, (void *)&for_here));
        }
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
                std::this_thread::sleep_for(std::chrono::milliseconds(1));
            }
        }
    }*/

        static void thread_core_function(void * args);
        static void serv_core_function(void * argOne, void * argTwo);
};


#endif //THREADTEST_WEB_SERV_H
