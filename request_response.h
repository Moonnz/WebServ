//
// Created by Martin on 09/09/2018.
//
#include "decl.h"
#ifndef THREADTEST_REQUEST_RESPONSE_H
#define THREADTEST_REQUEST_RESPONSE_H


class request_response {
public:
    request_response(std::string);
    std::vector<std::string> cut_by(std::string, std::string);
    std::string get_filename(std::string);
    int retrieve_file_data(std::string);
    inline bool file_exist(std::string);
    std::string get_response();
    bool keep_alive = false;
private:
    std::vector<std::string> lines;
    std::string file_content = "";
    std::string head = "";
    int error = 0;
    int file_size = 0;
};


#endif //THREADTEST_REQUEST_RESPONSE_H
