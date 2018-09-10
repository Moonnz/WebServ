//
// Created by Martin on 09/09/2018.
//

#include "request_response.h"

request_response::request_response(std::string request) {
    std::vector<std::string> lines;
    lines = cut_by(request, "\r\n\r\n");
    std::string file_name;
    int pos = lines[0].find("GET");
    file_name = lines[0].substr(pos, lines[0].length());
    std::cout << file_name << std::endl;

}

std::vector<std::string> request_response::cut_by(std::string _request , std::string by) {
    std::string request = _request;
    std::vector<std::string> to_return;
    bool stop = false;

    while(!stop){
        int pos = request.find(by);
        std::string temporaire = request.substr(0, pos);
        request = request.substr(pos+1, request.length());
        to_return.push_back(temporaire);
        if(request.length() < 4){
            stop = !stop;
        }
    }
    return to_return;
}