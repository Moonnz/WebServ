//
// Created by Martin on 09/09/2018.
//
#include "decl.h"
#ifndef THREADTEST_REQUEST_RESPONSE_H
#define THREADTEST_REQUEST_RESPONSE_H


class request_response {
public:
    request_response(std::string);
    static std::vector<std::string> cut_by(std::string, std::string);

};


#endif //THREADTEST_REQUEST_RESPONSE_H
