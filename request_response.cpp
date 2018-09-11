//
// Created by Martin on 09/09/2018.
//

#include "request_response.h"

request_response::request_response(std::string request) {
    lines = cut_by(request, "\r\n");
    std::cout << "filename: " << get_filename(request) << std::endl;

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

std::string request_response::get_filename(std::string request){
    std::string file_name;
    int pos_slash = lines[0].find("/");
    int pos_space = lines[0].find_last_of(" ");
    file_name = lines[0].substr(pos_slash, pos_space-pos_slash);
    return file_name.substr(1, file_name.length());

}

std::string request_response::retrieve_file_data(std::string filename){
    std::ifstream file;
    file.open(filename);
    
}