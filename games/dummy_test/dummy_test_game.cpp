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
    state_load{new StateLoad()},
    state_menu{new StateMenu()},
    state_play{new StatePlay()}
    {
        UfoGlobal::program.game = this;
        UfoGlobal::program.game->game_states["load"] = state_load;
        UfoGlobal::program.game->game_states["menu"] = state_menu;
        UfoGlobal::program.game->game_states["play"] = state_play;

        game_state = state_load;
        state_load->SetLoad("../games/dummy_test/res/map/windmill/windmill.json");
        //UfoGlobal::program.cell_map.LoadMap("../games/dummy_test/res/map/windmill/windmill.json");
        UfoGlobal::program.asset_manager.LoadDecal("../games/dummy_test/res/masks/pill_small.png", "decPin");
        UfoGlobal::program.entities.push_back(new Dummy(olc::vf2d(450.0f, 50.0f)));
        UfoGlobal::program.camera.scale = 3.0f;

    }

DummyTestGame::~DummyTestGame(){
    delete state_load;
    delete state_menu;
    delete state_play;
}