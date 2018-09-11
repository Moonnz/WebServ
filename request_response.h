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
    std::string get_filename(std::string);
    std::string retrieve_file_data(std::string);
private:
    std::vector<std::string> lines;

};


#endif //THREADTEST_REQUEST_RESPONSE_H
