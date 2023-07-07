#include "dummy_test_game.h"
#include "../../src/ufo/game.h"

DummyTestGame::DummyTestGame() :
    Game(),
    state_load{new StateLoad()},
    state_menu{new StateMenu()},
    state_play{new StatePlay()}
    {
        game_state = state_play;
    }
DummyTestGame::~DummyTestGame(){
    delete state_load;
    delete state_menu;
    delete state_play;
}