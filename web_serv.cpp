//
// Created by root on 04/09/18.
//

#include "web_serv.h"

web_serv::web_serv() {
    container a;

    a.stop = false;
    recsize = sizeof(sin);
    crecsize = sizeof(csin);

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
}

