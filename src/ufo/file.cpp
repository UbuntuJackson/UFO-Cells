#include "file.h"
#include <fstream>
#include <sstream>
#include <string>

File::File(){}

File::File(std::string _path){
    ReadAsStream(_path);
}

std::stringstream& File::ReadAsStream(std::string _path){
    std::ifstream ifs;
    ifs.open(_path);
    std::stringstream sstr;
    contents << ifs.rdbuf();
    ifs.close();
    return contents;
}

std::string File::GetAsString(){
    return contents.str();
}

std::string File::ReadAsString(std::string _path){
    std::ifstream ifs;
    ifs.open(_path);
    std::stringstream sstr;
    contents << ifs.rdbuf();
    ifs.close();
    return contents.str();
}



void File::Write(std::string _filename, std::string _text){
    std::ofstream outfile(_filename);
    outfile << contents.str() << std::endl;
    outfile.close();
}