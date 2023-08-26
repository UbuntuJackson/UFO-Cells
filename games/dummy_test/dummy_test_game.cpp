#include "dummy_test_game.h"
#include "../../src/ufo/game.h"
#include "../../src/program/ufo_global.h"
#include "dummy.h"
#include "../../external/olcPixelGameEngine.h"
#include "state_load.h"
#include "state_menu.h"
#include "state_play.h"

DummyTestGame::DummyTestGame() :
    Game(),
    state_load{new StateLoad(this)},
    state_menu{new StateMenu(this)},
    state_play{new StatePlay(this)}
    {
        //UfoGlobal::program.camera.m_camera_state = MOUSE;
        game_states["load"] = state_load; //maybe have an addstate function
        game_states["menu"] = state_menu;
        game_states["play"] = state_play;

        SetState("load", "../games/dummy_test/res/map/windmill/windmill.json");

    }

DummyTestGame::~DummyTestGame(){
    delete state_load;
    delete state_menu;
    delete state_play;
}

void
DummyTestGame::LoadResources(){
    UfoGlobal::game->asset_manager.LoadDecal("../games/dummy_test/res/masks/pill_small.png", "decPin");
    UfoGlobal::game->asset_manager.LoadDecal("../res/misc/new_logo_centred_ufo_cells.png", "load");
    UfoGlobal::game->asset_manager.LoadDecal("../games/dummy_test/res/map/zen/dynamic_solid_1.png", "dynamic_solid");
}