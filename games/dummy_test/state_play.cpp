#include "state_play.h"
#include "../../src/program/ufo_global.h"
#include <iostream>
#include "../../src/ufo/game.h"
#include "dummy.h"

StatePlay::StatePlay(): State(){}

void StatePlay::Set(std::string _data){

}

void StatePlay::Update(){
    olc::vf2d world_pos = UfoGlobal::program.camera.ScreenToWorld(UfoGlobal::program.GetMousePos(), olc::vf2d(0.0f, 0.0f));

    if(UfoGlobal::program.GetKey(olc::ESCAPE).bPressed){UfoGlobal::program.game->SetState("menu", "PauseMenu");}

    for(auto e : UfoGlobal::program.entities){
        e->Update();
    }
    //std::cout << world_pos.x << ", " << world_pos.y << std::endl;
    UfoGlobal::program.cell_map.Draw();
}
