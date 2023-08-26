#include "state_play.h"
#include "../../src/program/ufo_global.h"
#include <iostream>
#include "../../src/ufo/game.h"
#include "dummy.h"

StatePlay::StatePlay(Game* _game): State(_game){}

void StatePlay::Set(std::string _data){

}

void StatePlay::Update(){
    olc::vf2d world_pos = UfoGlobal::game->camera.ScreenToWorld(UfoGlobal::game->GetMousePos(), olc::vf2d(0.0f, 0.0f));

    if(UfoGlobal::game->GetKey(olc::ESCAPE).bPressed){UfoGlobal::game->SetState("menu", "PauseMenu");}

    for(auto layer : UfoGlobal::game->cell_map.layers){
        layer -> Update();
    }
    UfoGlobal::game->cell_map.Draw();
}
