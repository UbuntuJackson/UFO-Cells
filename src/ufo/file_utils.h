#ifndef FILE_UTILS_H
#define FILE_UTILS_H

#include <string>
#include <sstream>
#include <fstream>

std::string PutFileIntoString(std::ifstream& in);
std::string WriteFile(std::string _text, std::string _filename);
#endif