#include "entity.h"
#include "program.h"
#include "colour_utils.h"
#include <cmath>

Entity::Entity(Program *_program,olc::vf2d _position) : program{_program}, position{_position}{
    is_grounded = false;
    was_grounded = false;
    snap_to_ground = 16;
}

void
Entity::Update(){
    
    //if(program->GetKey(olc::Key::DOWN).bHeld) velocity.y += 0.1f;
    //if(program->GetKey(olc::Key::UP).bHeld) velocity.y -= 0.1f;
    
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
        std::cout << HeightUntilGround(program->asset_manager.decPin) << std::endl;
        position.y = std::floor(position.y);
        if(HeightUntilGround(program->asset_manager.decPin) < snap_to_ground){
            while(!IsOverlapping(program->asset_manager.decPin)){
                
                position.y += 1.0f;

            }
            position.y -= 1.0f;
            is_grounded = true;
            //
        }
    }

    was_grounded = is_grounded;

    if(program->GetKey(olc::Key::RIGHT).bHeld) velocity.x += 0.2f;
    if(program->GetKey(olc::Key::LEFT).bHeld) velocity.x -= 0.2f;

    position.x += velocity.x;
    velocity.x *= 0.95f;

    if(IsOverlapping(program->asset_manager.decPin)){
        if(IsOverlappingHeight(program->asset_manager.decPin) > int(position.y) +22 && (is_grounded || was_grounded)){
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

    
}

int
Entity::IsOverlappingHeight(olc::Decal *_decal){
    for(int y = position.y; y < position.y + _decal->sprite->Size().y; y++){
        for(int x = position.x; x < position.x + _decal->sprite->Size().x; x++){
            if(CompareColour(_decal->sprite->GetPixel(x- position.x, y- position.y), olc::WHITE)
                && CompareColour(program->asset_manager.decMap->sprite->GetPixel(x, y), olc::WHITE)
            ){
                return y;
            }
        }
    }
    return position.y + _decal->sprite->Size().y;
}

int
Entity::HeightUntilGround(olc::Decal *_decal){
    for(int y = position.y + _decal->sprite->Size().y; y < position.y + _decal->sprite->Size().y + snap_to_ground; y++){
        for(int x = position.x; x < position.x + _decal->sprite->Size().x; x++){
            if(CompareColour(program->asset_manager.decMap->sprite->GetPixel(x,y), olc::WHITE)){
                return y -(position.y + _decal->sprite->Size().y);
            }
        }
    }
    return snap_to_ground;
}

bool
Entity::IsOverlapping(olc::Decal *_decal){
    for(int y = position.y; y < position.y + _decal->sprite->Size().y; y++){
        for(int x = position.x; x < position.x + _decal->sprite->Size().x; x++){
            if(CompareColour(_decal->sprite->GetPixel(x- position.x, y- position.y), olc::WHITE)
                && CompareColour(program->asset_manager.decMap->sprite->GetPixel(x, y), olc::WHITE)
            ){
                return true;
            }
        }
    }
    return false;
}

void
Entity::Draw(){
    program->DrawDecal(
        position,
        program -> asset_manager.decPin, olc::vf2d(1.0f, 1.0f));
}