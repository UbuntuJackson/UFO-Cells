#include "file_utils.h"
#include <string>
#include <sstream>
#include <fstream>

std::string PutFileIntoString(std::ifstream& in) {
    std::ostringstream sstr;
    sstr << in.rdbuf();
    return sstr.str();
}