#include "dynamic_solid.h"
#include "cell_actor.h"
#include <string>
#include "../program/ufo_global.h"

DynamicSolid::DynamicSolid(olc::vf2d _position, std::string _mask) : CellActor(_position), mask{_mask}{
    velocity = {-0.2f, 0.0f};
    timelapse = 0;
}

void DynamicSolid::Update(){
    if(timelapse > 1000){velocity *= -1.0f; timelapse = 0;}
    timelapse++;
    std::cout << timelapse << std::endl;
    position.x += velocity.x;
}
void DynamicSolid::Draw(){
    UfoGlobal::program.camera.DrawDecal(
        position,
        UfoGlobal::program.asset_manager.GetDecal(mask));
}