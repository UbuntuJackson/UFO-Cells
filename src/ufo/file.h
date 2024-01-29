#ifndef FILE_H
#define FILE_H

#include <string>

class File{
public:
    std::string contents;
    File();
    File(std::string _path);
    std::string Read(std::string _path);
    void Write(std::string _filename, std::string _text);
    void In(std::string  _text);
};

#endif