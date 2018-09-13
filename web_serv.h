//
// Created by root on 04/09/18.
//

#ifndef THREADTEST_WEB_SERV_H
#define THREADTEST_WEB_SERV_H

#include "decl.h"
#include "request_response.h"

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
        SOCKET sock;
        socklen_t recsize;

        static void thread_core_function(void *);
        static void serv_core_function(void *, void *);
};

#endif //THREADTEST_WEB_SERV_H
