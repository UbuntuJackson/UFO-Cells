#include "dummy.h"
#include "../../external/olcPixelGameEngine.h"
#include "../ufo/cell_actor.h"
#include "../program/program.h"
#include <cmath>
#include "../program/ufo_global.h"

Dummy::Dummy(olc::vf2d _position) : CellActor(_position){
    UfoGlobal::program.camera.scale = 2.0f;
    UfoGlobal::program.camera.SetStateFollowPlatfomer(this);

    //program->camera.SetStateZoom(3.0f);
}

void
Dummy::Update(){

    // INPUT X-AXIS

    if(UfoGlobal::program.GetKey(olc::Key::RIGHT).bHeld) velocity.x += 0.5f;
    if(UfoGlobal::program.GetKey(olc::Key::LEFT).bHeld) velocity.x -= 0.5f;

    olc::vf2d former_position = position;

    position.x += velocity.x;

    velocity.x *= 0.85f;

    //HEIGHT ADJUSTMENT OVERLAP

    if(IsOverlapping(UfoGlobal::program.asset_manager.decPin, solid_layer, position)){
        former_position.y = std::floor(former_position.y);

        if(velocity.x > 0.0f){
            former_position.x = std::floor(former_position.x);
        }
        if(velocity.x < 0.0f){
            former_position.x = std::ceil(former_position.x);
        }

        if(velocity.x > 0.0f){

            while(std::floor(former_position.x) != std::floor(position.x)+1.0f){
                if(IsOverlappingHeight(UfoGlobal::program.asset_manager.decPin, solid_layer, former_position) > int(former_position.y) + snap_up_range
                    && IsOverlappingHeight(UfoGlobal::program.asset_manager.decPin, solid_layer, former_position) != former_position.y +
                    UfoGlobal::program.asset_manager.decPin->sprite->Size().y){

                    while(IsOverlapping(UfoGlobal::program.asset_manager.decPin, solid_layer, former_position)){
                        former_position.y -= 1.0f;
                    }

                }

                former_position.x += 1.0f;
            }

            if(IsOverlappingHeight(UfoGlobal::program.asset_manager.decPin, solid_layer, former_position) > int(former_position.y) + snap_up_range){
                while(IsOverlapping(UfoGlobal::program.asset_manager.decPin, solid_layer, former_position)){
                    former_position.y -= 1.0f;
                }
            }
        }

        if(velocity.x < 0.0f){
            while(former_position.x != std::floor(position.x)){

                if(IsOverlappingHeight(UfoGlobal::program.asset_manager.decPin, solid_layer, former_position) > int(former_position.y) + snap_up_range
                    && IsOverlappingHeight(UfoGlobal::program.asset_manager.decPin, solid_layer, former_position) != former_position.y +
                    UfoGlobal::program.asset_manager.decPin->sprite->Size().y){
                    while(IsOverlapping(UfoGlobal::program.asset_manager.decPin, solid_layer, former_position)){
                        former_position.y -= 1.0f;
                    }

                }

                former_position.x -= 1.0f;
            }

            if(IsOverlappingHeight(UfoGlobal::program.asset_manager.decPin, solid_layer, former_position) > int(former_position.y) + snap_up_range){
                while(IsOverlapping(UfoGlobal::program.asset_manager.decPin, solid_layer, former_position)){
                    former_position.y -= 1.0f;
                }

            }
        }
    }

    position.y = former_position.y;

    // COLLISION ADJUSTMENT X-AXIS

    AdjustCollisionX();

    // ADJUSTMENT ALONG Y-AXIS

    velocity.y += 0.7f;

    is_grounded = false;

    position.y += velocity.y;
    velocity.y *= 0.99f;

    AdjustCollisionY();

    if(UfoGlobal::program.GetKey(olc::Key::Z).bPressed && (was_grounded || is_grounded)) velocity.y = -10.0f;

    //HEIGHT ADJUSTMENT SNAP_TO_GROUND

    if(was_grounded == true && is_grounded == false && velocity.y > 0.0f){
        position.y = std::floor(position.y);
        if(HeightUntilGround(UfoGlobal::program.asset_manager.decPin, solid_layer, position) < snap_to_ground){
            while(!IsOverlapping(UfoGlobal::program.asset_manager.decPin, solid_layer, position)){

                position.y += 1.0f;

            }
            position.y -= 1.0f;
            is_grounded = true;
        }
    }

    was_grounded = is_grounded;
}

void
Dummy::AdjustCollisionX(){
    if(IsOverlapping(UfoGlobal::program.asset_manager.decPin, solid_layer, position)){
        if(velocity.x > 0.0f){
            position.x = std::floor(position.x);
            while(IsOverlapping(UfoGlobal::program.asset_manager.decPin, solid_layer, position)){
                position.x -= 1.0f;
            }
        }
        if(velocity.x < 0.0f){
            position.x = std::ceil(position.x);
            while(IsOverlapping(UfoGlobal::program.asset_manager.decPin, solid_layer, position)){
                position.x += 1.0f;
            }
        }
        velocity.x = 0.0f;
    }
}

void
Dummy::AdjustCollisionY(){
    if(IsOverlapping(UfoGlobal::program.asset_manager.decPin, solid_layer, position)){
        if(velocity.y > 0.0f){
            is_grounded = true;
            position.y = std::floor(position.y);
            while(IsOverlapping(UfoGlobal::program.asset_manager.decPin, solid_layer, position)){
                position.y -= 1.0f;
            }
        }
        if(velocity.y < 0.0f){
            position.y = std::ceil(position.y);
            while(IsOverlapping(UfoGlobal::program.asset_manager.decPin, solid_layer, position)){
                position.y += 1.0f;
            }
        }

        velocity.y = 0.0f;
    }
}

void
Dummy::Draw(){
    UfoGlobal::program.camera.DrawDecal(
        position,
        UfoGlobal::program.asset_manager.decPin);
}