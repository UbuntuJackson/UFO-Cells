#ifndef GAME_H
#define GAME_H
#include "state.h"
#include <map>
#include <string>
#include "../../external/olcPixelGameEngine.h"
#include <squirrel.h>
#include "../ufo/assets.h"
#include "../ufo/cell_actor.h"
#include "../ufo/cellmap.h"
#include "../ufo/camera.h"

class Game : public olc::PixelGameEngine{
public:
    std::string game_dir_name;
    HSQUIRRELVM vm;

    bool record_input = true;
    bool play_input = false;

    bool running = true;
    float dt;

    Assets asset_manager; //Pass in this?
    //std::vector<CellActor*> entities; //Pass in this?
    //CellMap cell_map; //Pass in this?
    //Camera camera; //Attach to objects, probably, camera can have an owner
    State* game_state; //Pass in this in update function probably
    const olc::vf2d CHUNK_SIZE = {400, 400};
    std::map <std::string, State*> game_states;
    void SetState(std::string _state, std::string _data);
    virtual void LoadResources();
    bool OnUserCreate();
    bool OnUserUpdate(float fElapsedTime);
    Game();
    Game(State* _game_state);
    ~Game();
};

#endif