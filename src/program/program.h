#ifndef PROGRAM_H
#define PROGRAM_H
#include "../../external/olcPixelGameEngine.h"
#include "../ufo/assets.h"
#include "../ufo/cell_actor.h"
#include "../ufo/cellmap.h"
#include "../ufo/camera.h"

class Program : public olc::PixelGameEngine{
public:
    float dt;
    Assets asset_manager;
    std::vector<CellActor*> entities;
    CellMap cell_map;
    Camera camera;
    Program();
    ~Program();
    bool OnUserCreate();
    bool OnUserUpdate(float fElapsedTime);
};

#endif