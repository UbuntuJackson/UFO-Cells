#include "player_ray.h"
#include "../../external/olcPixelGameEngine.h"
#include "camera.h"
#include "game.h"
#include "cell_actor.h"
#include "colour_utils.h"
#include "cellmap.h"
#include "layer_solid.h"
PlayerRay::PlayerRay(Game* _game, Camera* _camera, CellActor* _host, olc::vf2d _relative_position): game{_game}, camera{_camera}, host{_host}, relative_position{_relative_position}, start{host->position}, end{host->position+olc::vf2d(1.0f,0.0f)}{}

olc::vf2d
PlayerRay::GetTargetPosition(){
    olc::vf2d target_position;
    olc::vf2d delta_position = camera->ScreenToWorld(game->GetMousePos(), {0.0f,0.0f}) - start;
    target_position = camera->ScreenToWorld(game->GetMousePos(), {0.0f,0.0f});
    if(delta_position.mag() > radius){
        target_position = start + delta_position.norm() * radius;
    }
    return target_position;
}

void
PlayerRay::OnCollision(){}

olc::vf2d PlayerRay::GetFirstHit(){
    return first_hit;
}

bool
PlayerRay::IsHitBitmap(olc::Decal* _decal){
    
    olc::vf2d sample_coordinate = start;
    //std::cout << sample_coordinate << std::endl;
    if((end-start).mag() == 0.0f) return false;
    olc::vf2d sample_direction = (end-start).norm()/2.0f;
    int increment = 0;
    float t = 0.0f;
    //float time_step = (end-start).norm().mag();
    while(!CompareColour(_decal->sprite->GetPixel(int(sample_coordinate.x), int(sample_coordinate.y)), olc::WHITE)){
        if((sample_coordinate-start).mag() > (end-start).mag()) return false;
        //if((sample_coordinate-start).mag() > 600.0f) break;
        sample_coordinate+=sample_direction;
    }
    if(CompareColour(_decal->sprite->GetPixel(int(sample_coordinate.x), int(sample_coordinate.y)), olc::WHITE)){
        first_hit = sample_coordinate;
        return true;
    }
    
    return false;
}

std::vector<olc::vf2d>
PlayerRay::GetAllCollisions(){
    
}

CellActor*
PlayerRay::GetFirstActorDetected(){

}

std::vector<CellActor*>
PlayerRay::GetAllActorsDetected(){

}

void
PlayerRay::Update(){
    start = host->position+relative_position;
    end = GetTargetPosition();
}

void
PlayerRay::Draw(Camera* _camera){
    if((end-start).mag() == 0.0f) return;
    game->DrawLineDecal(_camera->WorldToScreen(start, {0.0f,0.0f}), _camera->WorldToScreen(end, {0.0f,0.0f}), draw_colour);
}