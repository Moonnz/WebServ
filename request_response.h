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
    std::string get_filename();
    int retrieve_file_data(std::string);
    inline bool file_exist(std::string);
    std::string get_response();
    int get_response_size();
    void get_response_buf(char*);
    std::string get_extension();
    bool keep_alive = false;
    int error = 0;
private:
    std::vector<std::string> lines;
    std::string file_content = "";
    std::string head = "";
    char * file_content_buf;
    long file_size = 0;
};


#endif //THREADTEST_REQUEST_RESPONSE_H
