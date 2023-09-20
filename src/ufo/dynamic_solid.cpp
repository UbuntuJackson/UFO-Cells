#include "dynamic_solid.h"
#include "cell_actor.h"
#include <string>
#include "../program/ufo_global.h"
#include "camera.h"
#include <cmath>

DynamicSolid::DynamicSolid(olc::vf2d _position, Game* _game, std::string _mask) : CellActor(_position, _game, _mask){
    velocity = {-0.3f, -0.3f};
    timelapse = 0;
}

void DynamicSolid::Update(){
    position += velocity;
    angle+=0.01;
    velocity.x = 20.0f * -std::cos(angle); //change vel after movement to avoid wacky inaccurate adding of velocity
    velocity.y = 20.0f * std::sin(angle);
    std::cout << velocity.y << std::endl;
    timelapse++;
    //if(timelapse > 400){velocity *= -1.0f; timelapse = 0;}
}
void DynamicSolid::Draw(Camera* _camera){
    _camera->DrawDecal(
        position,
        game->asset_manager.GetDecal(mask));
}