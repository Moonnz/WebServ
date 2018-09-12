//
// Created by Martin on 09/09/2018.
//

#include "request_response.h"

request_response::request_response(std::string request) {
    lines = cut_by(request, "\r\n");
    error  = retrieve_file_data(get_filename());
    
    for(std::vector<std::string>::iterator it = lines.begin(); it != lines.end(); it++){
        std::size_t found = it->find("Connection: ");
        if(found != std::string::npos){
            std::transform(it->begin(), it->end(), it->begin(), ::tolower);
            if(it->substr(12, it->length()) == " keep-alive" && error != 5 && error != 10 ){
                keep_alive = true;
            }
        }
    }
    
    if(error == 0){
        head.append("HTTP/1.1 200 OK\r\nContent-Length: ");
        head.append(std::to_string(file_size));
        if(get_extension() == ".html")
            head.append("\r\nContent-type: text/html\r\n");
        else if(get_extension() == ".ico")
            head.append("\r\nContent-type: image/x-icon\r\n");
        else if(get_extension() == ".css")
            head.append("\r\nContent-type: text/css\r\n");
        if(keep_alive){
            head.append("Connection: Keep-Alive\r\nKeep-Alive: timeout=1, max=10\r\n\r\n");
        }else{
            head.append("Connection: Closed\r\n\r\n");
        }
    }else if(error == 5 || error == 10){
        head.append("HTTP/1.1 404 Not Found\r\nContent-Length: 0");
        head.append("\r\nConnection: Closed\r\n");
        head.append("Content-type: text/html\r\n\r\n");
    }
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

std::string request_response::get_filename(){
    std::string file_name;
    int pos_slash = lines[0].find("/");
    int pos_space = lines[0].find_last_of(" ");
    file_name = lines[0].substr(pos_slash, pos_space-pos_slash);
    if(file_name == "/")
        return "index.html";
    else
        return file_name.substr(1, file_name.length());
}

std::string request_response::get_extension(){
    std::string extension;
    int pos_dot = lines[0].find(".");
    int pos_space = lines[0].find_last_of(" ");
    extension = lines[0].substr(pos_dot, pos_space-pos_dot);
    return extension;
}

int request_response::retrieve_file_data(std::string _filename){
    std::string filename = __FILE_PATH;
    #if defined(WIN32)
        filename.append("\\");
    #else
        filename.append("/");
    #endif
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
        } else{
            std::cout << "error for: " << filename << std::endl;
            return 5;
        }
    }else{
        std::cout << "error for: " << filename << std::endl;
        return 10;
    }
}

bool request_response::file_exist(std::string filename) {
    struct stat buffer;
    return (stat ( filename.c_str(), &buffer) == 0);
}