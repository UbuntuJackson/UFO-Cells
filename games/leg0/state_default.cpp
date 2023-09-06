#include "state_default.h"
#include "leg0.h"
#include "../../src/ufo/game.h"
#include "../../src/ufo/camera.h"

StateDefault::StateDefault(Leg0* _game): State(_game), game{_game}{}

void
StateDefault::Update(){
    count++;
    if(count%60 == 0) flip = !flip;
    game->camera.DrawRotatedPartialDecal({100.0f,100.0f},game->asset_manager.GetDecal("snowman"),game->asset_manager.GetDecal("snowman")->sprite->Size()/2,{0.0f,0.0f}, game->asset_manager.GetDecal("snowman")->sprite->Size(), {-1.0f,-1.0f});
    //game->camera.DrawDecal({0.0f,0.0f}, game->asset_manager.GetDecal("snowman"));
}