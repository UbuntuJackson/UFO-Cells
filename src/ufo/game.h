#ifndef GAME_H
#define GAME_H
#include <map>
#include <string>
#include "../../external/olcPixelGameEngine.h"
#include <squirrel.h>
#include "../ufo/assets.h"
#include "../ufo/cell_actor.h"
#include "../ufo/camera.h"

class Game : public olc::PixelGameEngine{
public:
    std::string game_dir_name;
    HSQUIRRELVM vm;

    bool record_input = true;
    bool play_input = false;

    bool running = true;
    float game_time = 0.0f;
    float dt;

    Assets asset_manager; //Pass in this?
    //std::vector<CellActor*> entities; //Pass in this?
    //CellMap cell_map; //Pass in this?
    //Camera camera; //Attach to objects, probably, camera can have an owner
    const olc::vf2d CHUNK_SIZE = {400, 400};
    virtual void LoadResources();
    bool OnUserCreate();
    bool OnUserUpdate(float fElapsedTime);
    Game();
    ~Game();
};

#endif