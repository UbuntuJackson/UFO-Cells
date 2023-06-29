#ifndef CELLMAP_H
#define CELLMAP_H
#include <vector>
#include "olcPixelGameEngine.h"
#include <string>

class Program;

class CellMap{
public:
    Program *program;
    std::string map_path;
    std::vector<olc::Decal*> visible_layers;
    std::map<std::string, olc::Decal*> collision_layers;
    CellMap() = default;
    CellMap(Program *_program);
    ~CellMap();
    void LoadMap(std::string _map_path);
    void UnloadMap();
    void Draw();

};

#endif