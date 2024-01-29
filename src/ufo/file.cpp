#include "file.h"
#include <fstream>
#include <sstream>
#include <string>

File::File() : contents{""}{}

File::File(std::string _path) : contents{Read(_path)}{}

std::string File::Read(std::string _path){
    std::ifstream ifs;
    ifs.open(_path);
    std::ostringstream sstr;
    sstr << ifs.rdbuf();
    ifs.close();
    contents = sstr.str();
    return contents;
}
void File::Write(std::string _filename, std::string _text){
    std::ofstream outfile(_filename);
    outfile << _text << std::endl;
    outfile.close();
}
void File::In(std::string _text){

}