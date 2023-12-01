#ifndef FILE_UTILS_H
#define FILE_UTILS_H

#include <string>
#include <sstream>
#include <fstream>

std::string PutFileIntoString(std::ifstream& in);
void WriteFileFromString(std::string _text, std::string _filename);
std::string ReadFileToString(std::string _path);
bool FileExists(std::string _path);
#endif