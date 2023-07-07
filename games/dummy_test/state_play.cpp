#include "state_play.h"
#include "../../src/program/ufo_global.h"

StatePlay::StatePlay(){}

void StatePlay::SetPlay(std::string _map){}

void StatePlay::Update(){
    for(auto e : UfoGlobal::program.entities){
        e->Update();
    }

    UfoGlobal::program.cell_map.Draw();
}
