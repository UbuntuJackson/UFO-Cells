#include "player_ray.h"
#include "../../external/olcPixelGameEngine.h"
PlayerRay::PlayerRay(Game* _game, Camera* _camera): game{_game}, camera{_camera}{}

olc::vf2d
PlayerRay::GetTargetPosition(){
    olc::vf2d target_position;
    olc::vf2d delta_position = end - start;
    target_position = camera->ScreenToWorld(game->GetMousePos(), {0.0f,0.0f});
    target_position = game->GetMousePos();
    if(delta_position.mag() > radius){
        target_position = start + delta_position.norm() * radius;
    }
}

void
PlayerRay::OnCollision(){}

olc::vf2d
PlayerRay::GetFirstCollision(){

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
    end = GetTargetPosition();
}

void
PlayerRay::Draw(Camera* _camera){
    game->DrawLine(_camera->WorldToScreen(start, {0.0f,0.0f}), _camera->WorldToScreen(end, {0.0f,0.0f}), olc::RED);
}