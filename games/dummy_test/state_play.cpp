#include "state_play.h"
#include <iostream>
#include "../../src/ufo/game.h"
#include "dummy.h"
#include "dummy_test_game.h"
#include "game_base_state.h"

StatePlay::StatePlay(DummyTestGame* _game): GameBaseState(_game){}

void StatePlay::Set(std::string _data){

}

void StatePlay::Update(){
    olc::vf2d world_pos = game->camera.ScreenToWorld(game->GetMousePos(), olc::vf2d(0.0f, 0.0f));

    if(game->GetKey(olc::ESCAPE).bPressed){game->SetState("menu", "PauseMenu");}

    for(auto layer : game->map.layers){
        layer -> Update();
    }
    game->map.Draw(&(game->camera));
}
