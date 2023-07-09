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
        std::cout << "test_game.cpp" << std::endl;

        UfoGlobal::program.cell_map.LoadMap("../res/map/windmill/windmill.json");
        UfoGlobal::program.entities.push_back(new Dummy(olc::vf2d(450.0f, 50.0f)));
        UfoGlobal::program.camera.scale = 2.0f;
        game_state = state_load;
        state_load->SetLoad("../res/map/windmill/windmill.json");
    }

DummyTestGame::~DummyTestGame(){
    delete state_load;
    delete state_menu;
    delete state_play;
}