//
// Created by Martin on 09/09/2018.
//

#include "request_response.h"

request_response::request_response(std::string request) {
    std::vector<std::string> lines;
    lines = cut_by(request, "\r\n\r\n");

}

std::vector<std::string> request_response::cut_by(std::string request , std::string by) {
    std::vector<std::string> to_return;
    bool stop = false;

    while(!stop){
        int pos = request.find(by);
        std::string temporaire = request.substr(0, pos);
        std::cout << "FROM CUT_BY: ";
        std::cout << temporaire << std::endl;
        request = request.substr(pos, request.length());
        to_return.push_back(temporaire);
        stop = true;
    }
    return to_return;
}