#ifndef PROGRAM_H
#define PROGRAM_H
#include "olcPixelGameEngine.h"
#include "assets.h"
#include "cell_actor.h"
#include "cellmap.h"

class Program : public olc::PixelGameEngine{
public:
    Assets asset_manager;
    std::vector<CellActor*> entities;
    CellMap cell_map;
    Program();
    ~Program();
    bool OnUserCreate();
    bool OnUserUpdate(float fElapsedTime);
};

#endif