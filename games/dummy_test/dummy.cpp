#include "dummy.h"
#include "../../external/olcPixelGameEngine.h"
#include "../../src/ufo/cell_actor.h"
#include "../../src/program/program.h"
#include <cmath>
#include "../../src/program/ufo_global.h"
#include <iostream>
#include "dummy_test_layer_actor.h"

Dummy::Dummy(olc::vf2d _position) : CellActor(_position){
    UfoGlobal::program.camera.SetStateFollowPlatfomer(this);
    mask = "decPin";
    mask_decal = UfoGlobal::program.asset_manager.GetDecal(mask);
}

void
Dummy::Update(){
    DummyTestLayerActor* act_layer;

    for(auto layer : UfoGlobal::program.cell_map.layers){
        if(layer->name == "dynamic_solids"){
            act_layer = dynamic_cast<DummyTestLayerActor*>(layer);
            if(act_layer == nullptr){
                std::cout << "dummy.cpp cast failed" << std::endl;
            }
        }
    }

    // INPUT X-AXIS
    if(UfoGlobal::program.GetKey(olc::Key::RIGHT).bHeld) velocity.x += 0.5f;
    if(UfoGlobal::program.GetKey(olc::Key::LEFT).bHeld) velocity.x -= 0.5f;

    former_position = position;

    position.x += velocity.x;
    velocity.x *= 0.85f;

    //HEIGHT ADJUSTMENT OVERLAP
    AdjustUpSlope();
    // COLLISION ADJUSTMENT X-AXIS
    AdjustCollisionX();
    //ThisVsDynamicSolid
    for(auto act : act_layer->actors){
        olc::vf2d act_new_position = act->position;
        act_new_position.x = act->position.x + act->velocity.x;

        if(IsOverlappingOtherDecal(mask_decal, position, UfoGlobal::program.asset_manager.GetDecal(act->mask), act_new_position)){
            if((act->velocity.x < 0.0f && velocity.x == 0.0f) || velocity.x > 0.0f){
                position.x = std::floor(position.x);
                while(IsOverlappingOtherDecal(mask_decal, position, UfoGlobal::program.asset_manager.GetDecal(act->mask), act_new_position)){
                    position.x -= 1.0f;
                }
            }
            if((act->velocity.x > 0.0f && velocity.x == 0.0f) || velocity.x < 0.0f){
                position.x = std::ceil(position.x);
                while(IsOverlappingOtherDecal(mask_decal, position, UfoGlobal::program.asset_manager.GetDecal(act->mask), act_new_position)){
                    position.x += 1.0f;
                }
            }
            velocity.x = 0.0f;
        }
    }

    // ADJUSTMENT ALONG Y-AXIS
    is_already_in_semi_solid = false;
    is_already_in_semi_solid = IsOverlapping(mask_decal, solid_layer, position, olc::RED);

    //if(UfoGlobal::program.GetKey(olc::Key::UP).bHeld) velocity.y -= 0.5f;
    //if(UfoGlobal::program.GetKey(olc::Key::DOWN).bHeld) velocity.y += 0.5f;

    velocity.y += 0.7f;
    is_grounded = false;
    position.y += velocity.y;
    velocity.y *= 0.99f;

    AdjustCollisionY();

    for(auto act : act_layer->actors){
        olc::vf2d act_new_position = act->position;
        act_new_position = act->position + act->velocity;

        if(IsOverlappingOtherDecal(mask_decal, position, UfoGlobal::program.asset_manager.GetDecal(act->mask), act_new_position)){
            if((act->velocity.y < 0.0f && velocity.y == 0.0f) || velocity.y > 0.0f){ //next frame
                is_grounded = true;
                position.y = std::floor(position.y);
                while(IsOverlappingOtherDecal(mask_decal, position, UfoGlobal::program.asset_manager.GetDecal(act->mask), act_new_position)){
                    position.y -= 1.0f;
                }
            }
            if((act->velocity.y > 0.0f && velocity.y == 0.0f) || velocity.y < 0.0f){
                position.y = std::ceil(position.y);
                while(IsOverlappingOtherDecal(mask_decal, position, UfoGlobal::program.asset_manager.GetDecal(act->mask), act_new_position)){
                    position.y += 1.0f;
                }
            }

            velocity.y = 0.0f;
            std::cout << int(act_new_position.y) << "," << int(position.y + 22) << std::endl;
        }
    }
    //both damn conditions are fulfilled, it moves in the opposite of the player, while the player is moving in the same direction

    if(UfoGlobal::program.GetKey(olc::Key::Z).bPressed && (was_grounded || is_grounded)) velocity.y = -10.0f;

    AdjustDownSlope();

    was_grounded = is_grounded;
}

void
Dummy::AdjustCollisionX(){
    if(IsOverlapping(mask_decal, solid_layer, position)){
        if(velocity.x > 0.0f){
            position.x = std::floor(position.x);
            while(IsOverlapping(mask_decal, solid_layer, position)){
                position.x -= 1.0f;
            }
        }
        if(velocity.x < 0.0f){
            position.x = std::ceil(position.x);
            while(IsOverlapping(mask_decal, solid_layer, position)){
                position.x += 1.0f;
            }
        }
        velocity.x = 0.0f;
    }
}

void
Dummy::AdjustCollisionY(){
    if(IsOverlapping(mask_decal, solid_layer, position)){
        if(velocity.y > 0.0f){
            is_grounded = true;
            position.y = std::floor(position.y);
            while(IsOverlapping(mask_decal, solid_layer, position)){
                position.y -= 1.0f;
            }
        }
        if(velocity.y < 0.0f){
            position.y = std::ceil(position.y);
            while(IsOverlapping(mask_decal, solid_layer, position)){
                position.y += 1.0f;
            }
        }

        velocity.y = 0.0f;
    }

    //SEMI SOLID

    if(IsOverlapping(mask_decal, solid_layer, position, olc::RED) &&
        velocity.y > 0.0f &&
        !is_already_in_semi_solid){
        if(velocity.y > 0.0f){
            is_grounded = true;
            position.y = std::floor(position.y);
            while(IsOverlapping(mask_decal, solid_layer, position, olc::RED)){
                position.y -= 1.0f;
            }
        }
        if(velocity.y < 0.0f){
            position.y = std::ceil(position.y);
            while(IsOverlapping(mask_decal, solid_layer, position, olc::RED)){
                position.y += 1.0f;
            }
        }

        velocity.y = 0.0f;
    }
}

void
Dummy::AdjustUpSlope(){
    //SOLID

    if(IsOverlapping(mask_decal, solid_layer, position)){
        former_position.y = std::floor(former_position.y);

        if(velocity.x > 0.0f){
            former_position.x = std::floor(former_position.x);
        }
        if(velocity.x < 0.0f){
            former_position.x = std::ceil(former_position.x);
        }

        if(velocity.x > 0.0f){

            while(std::floor(former_position.x) != std::floor(position.x)+1.0f){
                if(IsOverlappingHeight(mask_decal, solid_layer, former_position) > int(former_position.y) + snap_up_range
                    && IsOverlappingHeight(mask_decal, solid_layer, former_position) != former_position.y +
                    mask_decal->sprite->Size().y){

                    while(IsOverlapping(mask_decal, solid_layer, former_position)){
                        former_position.y -= 1.0f;
                    }

                }

                former_position.x += 1.0f;
            }
            //if you're still in collision after moving +=1.0f, then you move up again
            if(IsOverlappingHeight(mask_decal, solid_layer, former_position) > int(former_position.y) + snap_up_range){
                while(IsOverlapping(mask_decal, solid_layer, former_position)){
                    former_position.y -= 1.0f;
                }
            }
        }

        if(velocity.x < 0.0f){
            while(former_position.x != std::floor(position.x)){

                if(IsOverlappingHeight(mask_decal, solid_layer, former_position) > int(former_position.y) + snap_up_range
                    && IsOverlappingHeight(mask_decal, solid_layer, former_position) != former_position.y +
                    mask_decal->sprite->Size().y){
                    while(IsOverlapping(mask_decal, solid_layer, former_position)){
                        former_position.y -= 1.0f;
                    }

                }

                former_position.x -= 1.0f;
            }

            if(IsOverlappingHeight(mask_decal, solid_layer, former_position) > int(former_position.y) + snap_up_range){
                while(IsOverlapping(mask_decal, solid_layer, former_position)){
                    former_position.y -= 1.0f;
                }

            }
        }
    }

    //SEMI SOLID ADJUST_HEIGHT

    if(IsOverlapping(mask_decal, solid_layer, position, olc::RED) && !is_already_in_semi_solid){
        former_position.y = std::floor(former_position.y);

        if(velocity.x > 0.0f){
            former_position.x = std::floor(former_position.x);
        }
        if(velocity.x < 0.0f){
            former_position.x = std::ceil(former_position.x);
        }

        if(velocity.x > 0.0f){

            while(std::floor(former_position.x) != std::floor(position.x)+1.0f){
                if(IsOverlappingHeight(mask_decal, solid_layer, former_position, olc::RED) > int(former_position.y) + snap_up_range
                    && IsOverlappingHeight(mask_decal, solid_layer, former_position, olc::RED) != former_position.y +
                    mask_decal->sprite->Size().y){

                    while(IsOverlapping(mask_decal, solid_layer, former_position, olc::RED)){
                        former_position.y -= 1.0f;
                    }

                }

                former_position.x += 1.0f;
            }

            if(IsOverlappingHeight(mask_decal, solid_layer, former_position, olc::RED) > int(former_position.y) + snap_up_range){
                while(IsOverlapping(mask_decal, solid_layer, former_position, olc::RED)){
                    former_position.y -= 1.0f;
                }
            }
        }

        if(velocity.x < 0.0f){
            while(former_position.x != std::floor(position.x)){

                if(IsOverlappingHeight(mask_decal, solid_layer, former_position, olc::RED) > int(former_position.y) + snap_up_range
                    && IsOverlappingHeight(mask_decal, solid_layer, former_position, olc::RED) != former_position.y +
                    mask_decal->sprite->Size().y){
                    while(IsOverlapping(mask_decal, solid_layer, former_position, olc::RED)){
                        former_position.y -= 1.0f;
                    }

                }

                former_position.x -= 1.0f;
            }

            if(IsOverlappingHeight(mask_decal, solid_layer, former_position, olc::RED) > int(former_position.y) + snap_up_range){
                while(IsOverlapping(mask_decal, solid_layer, former_position, olc::RED)){
                    former_position.y -= 1.0f;
                }

            }
        }
    }
    position.y = former_position.y;
}

void
Dummy::AdjustDownSlope(){
    //HEIGHT ADJUSTMENT SNAP_TO_GROUND

    if(was_grounded == true && is_grounded == false && velocity.y > 0.0f){
        position.y = std::floor(position.y);
        if(HeightUntilGround(mask_decal, solid_layer, position) < snap_to_ground){
            while(!IsOverlapping(mask_decal, solid_layer, position)){

                position.y += 1.0f;

            }
            position.y -= 1.0f;
            is_grounded = true;
        }
    }

    //SEMI SOLID HEIGHT ADJUSTMENT SNAP_TO_GROUND
    if(was_grounded == true && is_grounded == false && velocity.y > 0.0f){
        position.y = std::floor(position.y);
        if(HeightUntilGround(mask_decal, solid_layer, position, olc::RED) < snap_to_ground){
            while(!IsOverlapping(mask_decal, solid_layer, position, olc::RED)){

                position.y += 1.0f;

            }
            position.y -= 1.0f;
            is_grounded = true;
        }
    }
}

void
Dummy::Draw(){
    UfoGlobal::program.camera.DrawDecal(
        position,
        mask_decal);
}