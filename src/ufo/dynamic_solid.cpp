#include "dynamic_solid.h"
#include "cell_actor.h"
#include <string>
#include "../program/ufo_global.h"

DynamicSolid::DynamicSolid(olc::vf2d _position, std::string _mask) : CellActor(_position, _mask){
    velocity = {-0.3f, -0.3f};
    timelapse = 0;
}

void DynamicSolid::Update(){
    position += velocity;
    timelapse++;
    if(timelapse > 400){velocity *= -1.0f; timelapse = 0;}
}
void DynamicSolid::Draw(){
    UfoGlobal::program.camera.DrawDecal(
        position,
        UfoGlobal::program.asset_manager.GetDecal(mask));
}