#include "state_default.h"
#include "leg0.h"
#include "../../src/ufo/game.h"

StateDefault::StateDefault(Game* _game): State(_game){}

void
StateDefault::Update(){
    game->Clear(olc::GREY);
    count++;
    if(count%60 == 0) flip = !flip;
    game->DrawRotatedDecal({500.0f,500.0f},game->asset_manager.GetDecal("snowman"), count/200.0f, game->asset_manager.GetDecal("snowman")->sprite->Size()/2, {1.0f,1.0f});
    
}