#include "dummy.h"
#include "../../external/olcPixelGameEngine.h"
#include "../../src/ufo/cell_actor.h"
#include "../../src/program/program.h"
#include <cmath>
#include "../../src/program/ufo_global.h"
#include <iostream>

Dummy::Dummy(olc::vf2d _position) : CellActor(_position){
    UfoGlobal::program.camera.SetStateFollowPlatfomer(this);
    mask = "decPin";
}

void
Dummy::Update(){
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

    // ADJUSTMENT ALONG Y-AXIS
    is_already_in_semi_solid = false;
    is_already_in_semi_solid = IsOverlapping(UfoGlobal::program.asset_manager.GetDecal(mask), solid_layer, position, olc::RED);

    velocity.y += 0.7f;

    is_grounded = false;

    position.y += velocity.y;
    velocity.y *= 0.99f;

    AdjustCollisionY();

    if(UfoGlobal::program.GetKey(olc::Key::Z).bPressed && (was_grounded || is_grounded)) velocity.y = -10.0f;

    AdjustDownSlope();

    was_grounded = is_grounded;
}

void
Dummy::AdjustCollisionX(){
    if(IsOverlapping(UfoGlobal::program.asset_manager.GetDecal(mask), solid_layer, position)){
        if(velocity.x > 0.0f){
            position.x = std::floor(position.x);
            while(IsOverlapping(UfoGlobal::program.asset_manager.GetDecal(mask), solid_layer, position)){
                position.x -= 1.0f;
            }
        }
        if(velocity.x < 0.0f){
            position.x = std::ceil(position.x);
            while(IsOverlapping(UfoGlobal::program.asset_manager.GetDecal(mask), solid_layer, position)){
                position.x += 1.0f;
            }
        }
        velocity.x = 0.0f;
    }
}

void
Dummy::AdjustCollisionY(){
    if(IsOverlapping(UfoGlobal::program.asset_manager.GetDecal(mask), solid_layer, position)){
        if(velocity.y > 0.0f){
            is_grounded = true;
            position.y = std::floor(position.y);
            while(IsOverlapping(UfoGlobal::program.asset_manager.GetDecal(mask), solid_layer, position)){
                position.y -= 1.0f;
            }
        }
        if(velocity.y < 0.0f){
            position.y = std::ceil(position.y);
            while(IsOverlapping(UfoGlobal::program.asset_manager.GetDecal(mask), solid_layer, position)){
                position.y += 1.0f;
            }
        }

        velocity.y = 0.0f;
    }

    //SEMI SOLID

    if(IsOverlapping(UfoGlobal::program.asset_manager.GetDecal(mask), solid_layer, position, olc::RED) &&
        velocity.y > 0.0f &&
        !is_already_in_semi_solid){
        if(velocity.y > 0.0f){
            is_grounded = true;
            position.y = std::floor(position.y);
            while(IsOverlapping(UfoGlobal::program.asset_manager.GetDecal(mask), solid_layer, position, olc::RED)){
                position.y -= 1.0f;
            }
        }
        if(velocity.y < 0.0f){
            position.y = std::ceil(position.y);
            while(IsOverlapping(UfoGlobal::program.asset_manager.GetDecal(mask), solid_layer, position, olc::RED)){
                position.y += 1.0f;
            }
        }

        velocity.y = 0.0f;
    }
}

void
Dummy::AdjustUpSlope(){
    //SOLID

    if(IsOverlapping(UfoGlobal::program.asset_manager.GetDecal(mask), solid_layer, position)){
        former_position.y = std::floor(former_position.y);

        if(velocity.x > 0.0f){
            former_position.x = std::floor(former_position.x);
        }
        if(velocity.x < 0.0f){
            former_position.x = std::ceil(former_position.x);
        }

        if(velocity.x > 0.0f){

            while(std::floor(former_position.x) != std::floor(position.x)+1.0f){
                if(IsOverlappingHeight(UfoGlobal::program.asset_manager.GetDecal(mask), solid_layer, former_position) > int(former_position.y) + snap_up_range
                    && IsOverlappingHeight(UfoGlobal::program.asset_manager.GetDecal(mask), solid_layer, former_position) != former_position.y +
                    UfoGlobal::program.asset_manager.GetDecal(mask)->sprite->Size().y){

                    while(IsOverlapping(UfoGlobal::program.asset_manager.GetDecal(mask), solid_layer, former_position)){
                        former_position.y -= 1.0f;
                    }

                }

                former_position.x += 1.0f;
            }
            //if you're still in collision after moving +=1.0f, then you move up again
            if(IsOverlappingHeight(UfoGlobal::program.asset_manager.GetDecal(mask), solid_layer, former_position) > int(former_position.y) + snap_up_range){
                while(IsOverlapping(UfoGlobal::program.asset_manager.GetDecal(mask), solid_layer, former_position)){
                    former_position.y -= 1.0f;
                }
            }
        }

        if(velocity.x < 0.0f){
            while(former_position.x != std::floor(position.x)){

                if(IsOverlappingHeight(UfoGlobal::program.asset_manager.GetDecal(mask), solid_layer, former_position) > int(former_position.y) + snap_up_range
                    && IsOverlappingHeight(UfoGlobal::program.asset_manager.GetDecal(mask), solid_layer, former_position) != former_position.y +
                    UfoGlobal::program.asset_manager.GetDecal(mask)->sprite->Size().y){
                    while(IsOverlapping(UfoGlobal::program.asset_manager.GetDecal(mask), solid_layer, former_position)){
                        former_position.y -= 1.0f;
                    }

                }

                former_position.x -= 1.0f;
            }
    
            if(IsOverlappingHeight(UfoGlobal::program.asset_manager.GetDecal(mask), solid_layer, former_position) > int(former_position.y) + snap_up_range){
                while(IsOverlapping(UfoGlobal::program.asset_manager.GetDecal(mask), solid_layer, former_position)){
                    former_position.y -= 1.0f;
                }

            }
        }
    }

    //SEMI SOLID ADJUST_HEIGHT

    if(IsOverlapping(UfoGlobal::program.asset_manager.GetDecal(mask), solid_layer, position, olc::RED) && !is_already_in_semi_solid){
        former_position.y = std::floor(former_position.y);

        if(velocity.x > 0.0f){
            former_position.x = std::floor(former_position.x);
        }
        if(velocity.x < 0.0f){
            former_position.x = std::ceil(former_position.x);
        }

        if(velocity.x > 0.0f){

            while(std::floor(former_position.x) != std::floor(position.x)+1.0f){
                if(IsOverlappingHeight(UfoGlobal::program.asset_manager.GetDecal(mask), solid_layer, former_position, olc::RED) > int(former_position.y) + snap_up_range
                    && IsOverlappingHeight(UfoGlobal::program.asset_manager.GetDecal(mask), solid_layer, former_position, olc::RED) != former_position.y +
                    UfoGlobal::program.asset_manager.GetDecal(mask)->sprite->Size().y){

                    while(IsOverlapping(UfoGlobal::program.asset_manager.GetDecal(mask), solid_layer, former_position, olc::RED)){
                        former_position.y -= 1.0f;
                    }

                }

                former_position.x += 1.0f;
            }

            if(IsOverlappingHeight(UfoGlobal::program.asset_manager.GetDecal(mask), solid_layer, former_position, olc::RED) > int(former_position.y) + snap_up_range){
                while(IsOverlapping(UfoGlobal::program.asset_manager.GetDecal(mask), solid_layer, former_position, olc::RED)){
                    former_position.y -= 1.0f;
                }
            }
        }

        if(velocity.x < 0.0f){
            while(former_position.x != std::floor(position.x)){

                if(IsOverlappingHeight(UfoGlobal::program.asset_manager.GetDecal(mask), solid_layer, former_position, olc::RED) > int(former_position.y) + snap_up_range
                    && IsOverlappingHeight(UfoGlobal::program.asset_manager.GetDecal(mask), solid_layer, former_position, olc::RED) != former_position.y +
                    UfoGlobal::program.asset_manager.GetDecal(mask)->sprite->Size().y){
                    while(IsOverlapping(UfoGlobal::program.asset_manager.GetDecal(mask), solid_layer, former_position, olc::RED)){
                        former_position.y -= 1.0f;
                    }

                }

                former_position.x -= 1.0f;
            }

            if(IsOverlappingHeight(UfoGlobal::program.asset_manager.GetDecal(mask), solid_layer, former_position, olc::RED) > int(former_position.y) + snap_up_range){
                while(IsOverlapping(UfoGlobal::program.asset_manager.GetDecal(mask), solid_layer, former_position, olc::RED)){
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
        if(HeightUntilGround(UfoGlobal::program.asset_manager.GetDecal(mask), solid_layer, position) < snap_to_ground){
            while(!IsOverlapping(UfoGlobal::program.asset_manager.GetDecal(mask), solid_layer, position)){

                position.y += 1.0f;

            }
            position.y -= 1.0f;
            is_grounded = true;
        }
    }

    //SEMI SOLID HEIGHT ADJUSTMENT SNAP_TO_GROUND
    if(was_grounded == true && is_grounded == false && velocity.y > 0.0f){
        position.y = std::floor(position.y);
        if(HeightUntilGround(UfoGlobal::program.asset_manager.GetDecal(mask), solid_layer, position, olc::RED) < snap_to_ground){
            while(!IsOverlapping(UfoGlobal::program.asset_manager.GetDecal(mask), solid_layer, position, olc::RED)){

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
        UfoGlobal::program.asset_manager.GetDecal(mask));
}