#ifndef FILE_H
#define FILE_H

#include <string>
#include <sstream>

class File{
public:
    std::stringstream contents;
    File();
    File(std::string _path);
    std::stringstream& ReadAsStream(std::string _path);
    std::stringstream& GetAsStream();
    std::string ReadAsString(std::string _path);
    std::string GetAsString();
    void Write(std::string _filename);
    
    template<typename ...Args>
    void Insert(Args&& ...args){
        (contents << ... << args);
    }
};

#endif