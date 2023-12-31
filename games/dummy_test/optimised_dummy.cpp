#include "optimised_dummy.h"
#include "../../external/olcPixelGameEngine.h"
#include "../../src/ufo/cell_actor.h"
#include "dummy_test_game.h"
#include "dummy_test_layer_actor.h"

OptimisedDummy::OptimisedDummy(olc::vf2d _position, DummyTestGame* _game) : CellActor(_position, _game), game{static_cast<DummyTestGame*>(_game)}{
    game->camera.SetStateFollowPlatfomer(this, {0.0f, 0.0f}, game->map.map_size);
    game->camera.scale = 2.0f;
    mask = "decPin";
    mask_decal = game->asset_manager.GetDecal(mask);
    solid_layer = "solid";
    is_already_in_semi_solid = false;
}

void
OptimisedDummy::Update(){
    DummyTestLayerActor* act_layer;

    for(auto layer : game->map.layers){
        if(layer->name == "dynamic_solids"){
            act_layer = dynamic_cast<DummyTestLayerActor*>(layer);
            if(act_layer == nullptr){
                std::cout << "dummy.cpp cast failed" << std::endl;
            }
        }
    }

    if(IsOverlapping(&(game->map),mask_decal,solid_layer,{position.x,position.y+1.0f}) ||
        IsOverlapping(&(game->map),mask_decal,solid_layer,{position.x,position.y+1.0f}, olc::RED)){
        is_grounded = true;        
    }

    // INPUT X-AXIS
    if(game->GetKey(olc::Key::RIGHT).bHeld) velocity.x += 0.5f;
    if(game->GetKey(olc::Key::LEFT).bHeld) velocity.x -= 0.5f;
    if((game->GetKey(olc::Key::Z).bPressed) && is_grounded){
        velocity.y = -10.0f;
    }

    former_position = position;

    AdjustEnteredDynamicSolidX(act_layer);

    position.x += velocity.x;
    velocity.x *= 0.85f;

    //HEIGHT ADJUSTMENT OVERLAP
    AdjustUpSlope(&(game->map));
    // COLLISION ADJUSTMENT X-AXIS
    AdjustCollisionX(&(game->map));
    //ThisVsDynamicSolid
    AdjustEnterDynamicSolidX(act_layer);

    // ADJUSTMENT ALONG Y-AXIS
    is_already_in_semi_solid = false;
    is_already_in_semi_solid = IsOverlapping(&(game->map), mask_decal, solid_layer, position, olc::RED);

    //Checking before we intend to move along the Y-Axis

    AdjustEnteredDynamicSolidY(act_layer);

    if((game->GetKey(olc::Key::Z).bPressed) && (was_grounded || is_grounded)){
        velocity.y = -10.0f;
    } //I would consider putting this right after the OnEnteredCollisionY() call, which would also mean that was_grounded = is_grounded needs to be put after that

    was_grounded = is_grounded;

    velocity.y += 0.7f;
    is_grounded = false;
    position.y += velocity.y;
    velocity.y *= 0.99f;

    AdjustCollisionY(&(game->map));

    AdjustEnterDynamicSolidY(act_layer);

    AdjustDownSlope(&(game->map));
}

void
OptimisedDummy::Draw(Camera* _camera){
    _camera->DrawDecal(
        position,
        game->asset_manager.GetDecal("decPurple"));
}