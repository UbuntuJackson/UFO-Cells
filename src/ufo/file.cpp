#include "file.h"
#include <fstream>
#include <sstream>

std::string File::Read(std::string _path){
    std::ifstream ifs;
    ifs.open(_path);
    std::ostringstream sstr;
    sstr << ifs.rdbuf();
    ifs.close();
    return sstr.str();
}
void File::Write(std::string _filename, std::string _text){
    std::ofstream outfile(_filename);
    outfile << _text << std::endl;
    outfile.close();
}
void File::In(std::string _text){

}