#include "file_utils.h"
#include <string>
#include <sstream>
#include <fstream>

std::string PutFileIntoString(std::ifstream& in) {
    std::ostringstream sstr;
    sstr << in.rdbuf();
    return sstr.str();
}

void WriteFileFromString(std::string _text, std::string _filename){
    std::ofstream outfile(_filename);
    outfile << _text << std::endl;
    outfile.close();
}

std::string ReadFileToString(std::string _path){
    std::ifstream ifs;
    ifs.open(_path);
    std::string file_from_stream = PutFileIntoString(ifs);
    ifs.close();
    return file_from_stream;
}

bool FileExists(std::string _path){
    std::ifstream ifs(_path.c_str());
    return ifs.good();
}