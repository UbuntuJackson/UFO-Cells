#ifndef PROGRAM_H
#define PROGRAM_H
#include "olcPixelGameEngine.h"
#include "assets.h"
#include "entity.h"

class Program : public olc::PixelGameEngine{
public:
    Assets asset_manager;
    std::vector<Entity> entities;
    Program();
    bool OnUserCreate();
    bool OnUserUpdate(float fElapsedTime);
};

#endif