#include "file_utils.h"
#include <string>
#include <sstream>
#include <fstream>

std::string PutFileIntoString(std::ifstream& in) {
    std::ostringstream sstr;
    sstr << in.rdbuf();
    return sstr.str();
}

std::string WriteFile(std::string _text, std::string _filename){
    std::ofstream outfile(_filename);
    outfile << _text << std::endl;
    outfile.close();
}