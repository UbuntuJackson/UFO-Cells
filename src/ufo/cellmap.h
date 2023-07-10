#ifndef CELLMAP_H
#define CELLMAP_H
#include <vector>
#include "../../external/olcPixelGameEngine.h"
#include <string>

class Program;

class CellMap{
public:
    olc::vf2d map_size;
    std::string map_path;
    std::vector<olc::Decal*> visible_layers;
    std::map<std::string, olc::Decal*> collision_layers;
    CellMap();
    ~CellMap();
    void LoadMap(std::string _map_path);
    void UnloadMap();
    void Draw();

};

#endif