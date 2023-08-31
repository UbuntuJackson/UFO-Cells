#include "custom_dynamic_solid.h"

CustomDynamicSolid::CustomDynamicSolid(olc::vf2d _position, DummyTestGame* _game, std::string _mask):
    DynamicSolid(_position, _game, _mask){}

void
CustomDynamicSolid::Draw(){
    game->camera.DrawDecal(
        position,
        game->asset_manager.GetDecal(mask));
}