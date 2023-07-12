#include "state_play.h"
#include "../../src/program/ufo_global.h"
#include <iostream>
#include "../../src/ufo/game.h"

StatePlay::StatePlay(): State(){}

void StatePlay::SetPlay(std::string _map){}

void StatePlay::Update(){
    olc::vf2d world_pos = UfoGlobal::program.camera.ScreenToWorld(UfoGlobal::program.GetMousePos(), olc::vf2d(0.0f, 0.0f));
    //std::cout << world_pos.x << ", " << world_pos.y << std::endl;

    for(auto e : UfoGlobal::program.entities){
        e->Update();
    }
    UfoGlobal::program.cell_map.Draw();
}
