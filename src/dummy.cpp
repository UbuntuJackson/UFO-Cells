#include "dummy.h"
#include "olcPixelGameEngine.h"
#include "cell_actor.h"
#include "program.h"

Dummy::Dummy(Program *_program,olc::vf2d _position) : CellActor(_program,_position){}

void
Dummy::Update(){

    // ADJUSTMENT ALONG X-AXIS

    if(program->GetKey(olc::Key::RIGHT).bHeld) velocity.x += 0.2f;
    if(program->GetKey(olc::Key::LEFT).bHeld) velocity.x -= 0.2f;

    position.x += velocity.x;
    velocity.x *= 0.95f;

    if(IsOverlapping(program->asset_manager.decPin)){
        if(IsOverlappingHeight(program->asset_manager.decPin) > int(position.y) + snap_up_range && (is_grounded || was_grounded)){
            position.y = std::floor(position.y);
            while(IsOverlapping(program->asset_manager.decPin)){
                position.y -= 1.0f;
            }
        }
        else{
            if(velocity.x > 0.0f){
                position.x = std::floor(position.x);
                while(IsOverlapping(program->asset_manager.decPin)){
                    position.x -= 1.0f;
                }
            }
            if(velocity.x < 0.0f){
                position.x = std::ceil(position.x);
                while(IsOverlapping(program->asset_manager.decPin)){
                    position.x += 1.0f;
                }
            }
            velocity.x = 0.0f;
        }

    }

    // ADJUSTMENT ALONG Y-AXIS

    velocity.y += 0.8f;
    velocity.y *= 0.99f;

    is_grounded = false;

    position.y += velocity.y;
    

    if(IsOverlapping(program->asset_manager.decPin)){
        if(velocity.y > 0.0f){
            is_grounded = true;
            position.y = std::floor(position.y);
            while(IsOverlapping(program->asset_manager.decPin)){
                position.y -= 1.0f;
            }
        }
        if(velocity.y < 0.0f){
            position.y = std::ceil(position.y);
            while(IsOverlapping(program->asset_manager.decPin)){
                position.y += 1.0f;
            }
        }

        velocity.y = 0.0f;
    }

    if(program->GetKey(olc::Key::Z).bPressed && (was_grounded || is_grounded)) velocity.y = -10.0f;

    if(was_grounded == true && is_grounded == false && velocity.y > 0.0f){
        position.y = std::floor(position.y);
        if(HeightUntilGround(program->asset_manager.decPin) < snap_to_ground){
            while(!IsOverlapping(program->asset_manager.decPin)){
                
                position.y += 1.0f;

            }
            position.y -= 1.0f;
            is_grounded = true;
        }
    }

    was_grounded = is_grounded;
}

void
Dummy::Draw(){
    program->DrawDecal(
        position,
        program -> asset_manager.decPin, olc::vf2d(1.0f, 1.0f));
}