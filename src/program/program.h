#ifndef PROGRAM_H
#define PROGRAM_H
#include "../../external/olcPixelGameEngine.h"
#include "../ufo/assets.h"
#include "../ufo/cell_actor.h"
#include "../ufo/cellmap.h"
#include "../ufo/camera.h"
#include <squirrel.h>
#include "../ufo/game.h"

class Program : public olc::PixelGameEngine{
public:
    bool record_input = true;
    bool play_input = false;

    Game* game;
    bool running = true;
    std::string game_dir_name;
    HSQUIRRELVM vm;
    float dt;
    Assets asset_manager; //Move to game baseclass
    std::vector<CellActor*> entities; //Move to game baseclass
    CellMap cell_map; //Cellmap should not either be instantiated as a member of the Program class
    Camera camera; //Camera instance should not be built in, it should just exist as a class
    Program();
    ~Program();
    void SetGame(Game* _game);
    bool OnUserCreate();
    bool OnUserUpdate(float fElapsedTime);
};

#endif