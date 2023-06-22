#ifndef CELLMAP_H
#define CELLMAP_H
#include <vector>
#include "olcPixelGameEngine.h"
class CellMap{
public:
    std::vector<olc::Decal*> layers;
    CellMap();
    void LoadMap();

};

#endif