//
// Created by Martin on 09/09/2018.
//

#include "request_response.h"

request_response::request_response(std::string request) {
    lines = cut_by(request, "\r\n");
    error  = retrieve_file_data(get_filename(request));
    if(error == 0){
        head.append("HTTP/1.1 200 OK\r\nContent-Length: ");
        head.append(std::to_string(file_size));
        head.append("\r\nContent-type: text/html\r\nConnection: Closed\r\n\r\n");
    }else if(error == 5 || error == 10){
        head.append("HTTP/1.1 400 OK\r\nContent-Length: 0");
        head.append("\r\nConnection: Closed\r\n\r\n");
    }
    std::cout << get_filename(request) << std::endl;
}

std::string request_response::get_response() {
    std::string a;
    if (error == 0){
        a.append(head.c_str());
        a.append(file_content.c_str());
    }else{
        a.append(head.c_str());
    }
    return a;
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
    if(file_name == "/")
        return "index.html";
    else
        return file_name.substr(1, file_name.length());

}

int request_response::retrieve_file_data(std::string _filename){
    std::string filename = __FILE_PATH;
    filename.append("\\");
    filename.append(_filename);
    if(file_exist(filename)){
        std::ifstream file(filename, std::ifstream::binary);
        if(file.good()){
            file.seekg(0, file.end);
            file_size = file.tellg();
            file.seekg(0, file.beg);
            std::cout << file_size << std::endl;
            char * buf = new char[file_size];
            file.read(buf, file_size);
            file.close();
            file_content = std::string(buf);
            return 0;
        } else
            return 5;
    }else
        return 10;
    
}

bool request_response::file_exist(std::string filename) {
    struct stat buffer;
    return (stat ( filename.c_str(), &buffer) == 0);
}