#ifndef PROGRAM_H
#define PROGRAM_H
#include "olcPixelGameEngine.h"
#include "assets.h"
#include "cell_actor.h"

class Program : public olc::PixelGameEngine{
public:
    Assets asset_manager;
    std::vector<CellActor*> entities;
    Program();
    ~Program();
    bool OnUserCreate();
    bool OnUserUpdate(float fElapsedTime);
};

#endif