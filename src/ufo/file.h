#ifndef FILE_H
#define FILE_H

#include <string>

class File{
    std::string contents;
    File();
    std::string Read(std::string _path);
    void Write(std::string _filename, std::string _text);
    void In(std::string  _text);
};

#endif