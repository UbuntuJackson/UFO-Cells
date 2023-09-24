#include "cell_actor.h"
#include "cellmap.h"
#include "colour_utils.h"
#include <string>
#include "../program/ufo_global.h"
#include "camera.h"
#include "../../external/olcPixelGameEngine.h"
#include <iostream>
#include "layer_actor.h"

CellActor::CellActor(olc::vf2d _position, Game *_game) :
    position{_position},
    game{_game},
    is_grounded{false},
    was_grounded{false},
    snap_to_ground{6},
    snap_up_range{16}
{
}

CellActor::CellActor(olc::vf2d _position, Game *_game, std::string _mask) :
    position{_position},
    game{_game},
    mask{_mask},
    is_grounded{false},
    was_grounded{false},
    snap_to_ground{6},
    snap_up_range{16}
{
}

CellActor::~CellActor(){}

bool
CellActor::IsOverlapping(CellMap* _map, olc::Decal *_decal, std::string _layer, olc::vf2d _position, olc::Pixel _colour){

    olc::Decal* collision_layer = _map->map_decals[_layer];

    for(int y = int(_position.y); y < int(_position.y) + _decal->sprite->Size().y; y++){
        for(int x = int(_position.x); x < int(_position.x) + _decal->sprite->Size().x; x++){
            if(CompareColour(_decal->sprite->GetPixel(x- int(_position.x), y- int(_position.y)), olc::WHITE)
                && CompareColour(collision_layer->sprite->GetPixel(x, y), _colour)
            ){
                return true;
            }
        }
    }
    return false;
}

bool
CellActor::IsOverlappingOtherDecal(olc::Decal *_decal, olc::vf2d _position, olc::Decal *_other_decal, olc::vf2d _other_position, olc::Pixel _colour){

    for(int y = int(_position.y); y < int(_position.y) + _decal->sprite->Size().y; y++){
        for(int x = int(_position.x); x < int(_position.x) + _decal->sprite->Size().x; x++){
            if(CompareColour(_decal->sprite->GetPixel(x- int(_position.x), y- int(_position.y)), olc::WHITE)
                && CompareColour(_other_decal->sprite->GetPixel(x - int(_other_position.x), y - int(_other_position.y)), _colour)
            ){
                return true;
            }
        }
    }
    return false;
}

int
CellActor::IsOverlappingHeight(CellMap* _map, olc::Decal *_decal, std::string _layer, olc::vf2d _position, olc::Pixel _colour){ //Pass in the map

    olc::Decal* collision_layer = _map->map_decals[_layer];

    for(int y = int(_position.y); y < int(_position.y) + _decal->sprite->Size().y; y++){
        for(int x = int(_position.x); x < int(_position.x) + _decal->sprite->Size().x; x++){
            if(CompareColour(_decal->sprite->GetPixel(x- int(_position.x), y- int(_position.y)), olc::WHITE)
                && CompareColour(collision_layer->sprite->GetPixel(x, y), _colour) //I'm gonna need a downcast or access the name from the asset manager
            ){
                return y;
            }
        }
    }
    return int(position.y) + _decal->sprite->Size().y;
}

//HeightUntilGround
//Used to make platforming type actors snap to ground as if they are walking down a slope, or stairs.
//Do a comparison between the value returned by this function and snap_to_ground
int
CellActor::HeightUntilGround(CellMap* _map, olc::Decal *_decal, std::string _layer, olc::vf2d _position, olc::Pixel _colour){

    olc::Decal* collision_layer = _map->map_decals[_layer];

    for(int y = int(_position.y) + _decal->sprite->Size().y; y < int(_position.y) + _decal->sprite->Size().y + snap_to_ground; y++){
        for(int x = int(_position.x); x < int(_position.x) + _decal->sprite->Size().x; x++){
            if(CompareColour(collision_layer->sprite->GetPixel(x,y), _colour)){

                //Difference between player bottom and highest collision cell
                return y -(int(_position.y) + _decal->sprite->Size().y);
            }
        }
    }
    //This is returned to consider it a non-snap case, too much space between actor and ground
    return snap_to_ground;
}

//should be IsOverlapping(olc::Decal *_decal, olc::vf2d _position, std::string _other_decal, olc::vf2d _other_position, olc::Pixel _colour)
//can make a function that iterates through actor layers and makes use of this function

void
CellActor::AdjustEnterDynamicSolidX(LayerActor* _act_layer){
    for(auto act : _act_layer->actors){
        olc::vf2d act_new_position = act->position;
        act_new_position.x = act->position.x + act->velocity.x;

        if(IsOverlappingOtherDecal(mask_decal, position, game->asset_manager.GetDecal(act->mask), act_new_position)){
            int a = 0;
            if(velocity.x > 0.0f){ //next frame
                position.x = std::floor(position.x);
                while(IsOverlappingOtherDecal(mask_decal, position, game->asset_manager.GetDecal(act->mask), act_new_position)){
                    position.x -= 1.0f;
                }
            }
            if(velocity.x < 0.0f){
                position.x = std::ceil(position.x);
                while(IsOverlappingOtherDecal(mask_decal, position, game->asset_manager.GetDecal(act->mask), act_new_position)){
                    position.x += 1.0f;
                }
            }
            velocity.x = 0.0f;
        }
    }
}

void
CellActor::AdjustEnterDynamicSolidY(LayerActor* _act_layer){
    for(auto act : _act_layer->actors){
        olc::vf2d act_new_position = act->position + act->velocity; //Maybe check for a different position

        if(IsOverlappingOtherDecal(mask_decal, position, game->asset_manager.GetDecal(act->mask), act_new_position)){
            if(velocity.y > 0.0f){
                position.y = std::floor(position.y);
                while(IsOverlappingOtherDecal(mask_decal, position, game->asset_manager.GetDecal(act->mask), act_new_position)){
                    position.y -= 1.0f;
                }
            }
            if(velocity.y < 0.0f){
                position.y = std::ceil(position.y);
                while(IsOverlappingOtherDecal(mask_decal, position, game->asset_manager.GetDecal(act->mask), act_new_position)){
                    position.y += 1.0f;
                }
            }
            velocity.y = 0.0f;
        }
    }
}

void
CellActor::AdjustEnterPseudoStaticSolidX(LayerActor* _act_layer){
    //We compare with the future state of DynamicSolid here to make sure we are out of collision by the end of the frame,
    //because if Player is relative to Dynamic solid, it is reasonable to emulate a scenario where both the x and y velocity is added
    //the behaviour should emulate that of a normal solid.
    for(auto act : _act_layer->actors){
        olc::vf2d act_new_position = act->position + act->velocity;

        if(IsOverlappingOtherDecal(mask_decal, position, game->asset_manager.GetDecal(act->mask), act_new_position)){
            std::cout << "help" << std::endl;
            int a = 0;
            if(velocity.x > 0.0f){ //next frame
                position.x = std::floor(position.x);
                while(IsOverlappingOtherDecal(mask_decal, position, game->asset_manager.GetDecal(act->mask), act_new_position)){
                    position.x -= 1.0f;
                }
            }
            if(velocity.x < 0.0f){
                position.x = std::ceil(position.x);
                while(IsOverlappingOtherDecal(mask_decal, position, game->asset_manager.GetDecal(act->mask), act_new_position)){
                    position.x += 1.0f;
                }
            }
            velocity.x = 0.0f;
        }
    }
}

void
CellActor::AdjustEnterPseudoStaticSolidY(LayerActor* _act_layer){
    //We compare with the future state of DynamicSolid here to make sure we are out of collision by the end of the frame,
    //because if Player is relative to Dynamic solid, it is reasonable to emulate a scenario where both the x and y velocity is added
    //the behaviour should emulate that of a normal solid.
    for(auto act : _act_layer->actors){
        olc::vf2d act_new_position = act->position + act->velocity;
        if(IsOverlappingOtherDecal(mask_decal, position, game->asset_manager.GetDecal(act->mask), act_new_position)){
            if(velocity.y > 0.0f){
                position.y = std::floor(position.y);
                while(IsOverlappingOtherDecal(mask_decal, position, game->asset_manager.GetDecal(act->mask), act_new_position)){
                    position.y -= 1.0f;
                }
            }
            if(velocity.y < 0.0f){
                position.y = std::ceil(position.y);
                while(IsOverlappingOtherDecal(mask_decal, position, game->asset_manager.GetDecal(act->mask), act_new_position)){
                    position.y += 1.0f;
                }
            }
            velocity.y = 0.0f;
        }
    }
}

void
CellActor::AdjustEnteredDynamicSolidX(LayerActor* _act_layer){
    for(auto act : _act_layer->actors){
        olc::vf2d act_new_position = act->position;
        act_new_position.x = act->position.x + act->velocity.x; //Dynamic solid moves in along the X-axis

        if(IsOverlappingOtherDecal(mask_decal, position, game->asset_manager.GetDecal(act->mask), act_new_position)){
            int a = 0;
            if(act->velocity.x < 0.0f){ //next frame
                position.x = std::floor(position.x);
                while(IsOverlappingOtherDecal(mask_decal, position, game->asset_manager.GetDecal(act->mask), act_new_position)){
                    position.x -= 1.0f;
                }
            }
            if(act->velocity.x > 0.0f){ //next frame
                position.x = std::ceil(position.x);
                while(IsOverlappingOtherDecal(mask_decal, position, game->asset_manager.GetDecal(act->mask), act_new_position)){
                    position.x += 1.0f;
                }
            }
            velocity.x = 0.0f;
        }
    }
}

void
CellActor::AdjustEnteredDynamicSolidY(LayerActor* _act_layer){
    for(auto act : _act_layer->actors){
        olc::vf2d act_new_position = act->position + act->velocity; //Dynamic solid moves in along the X-axis

        if(IsOverlappingOtherDecal(mask_decal, position, game->asset_manager.GetDecal(act->mask), act_new_position)){
            if(act->velocity.y < 0.0f){
                position.y = std::ceil(position.y);
                while(IsOverlappingOtherDecal(mask_decal, position, game->asset_manager.GetDecal(act->mask), act_new_position)){
                    position.y -= 1.0f;
                }
            }
            if(act->velocity.y > 0.0f){
                position.y = std::floor(position.y);
                while(IsOverlappingOtherDecal(mask_decal, position, game->asset_manager.GetDecal(act->mask), act_new_position)){
                    position.y += 1.0f;
                }
            }
            velocity.y = 0.0f;
        }
    }
}

void
CellActor::AdjustCollisionX(CellMap* _map){ //What information should be passed in?
    if(IsOverlapping(_map, mask_decal, solid_layer, position)){
        if(velocity.x > 0.0f){
            position.x = std::floor(position.x); //Do I need floor and ceil?
            while(IsOverlapping(_map,mask_decal, solid_layer, position)){
                position.x -= 1.0f;
            }
        }
        if(velocity.x < 0.0f){
            position.x = std::ceil(position.x);
            while(IsOverlapping(_map,mask_decal, solid_layer, position)){
                position.x += 1.0f;
            }
        }
        velocity.x = 0.0f;
    }
}

void
CellActor::AdjustCollisionY(CellMap* _map){
    if(IsOverlapping(_map,mask_decal, solid_layer, position)){
        if(velocity.y > 0.0f){
            position.y = std::floor(position.y);
            while(IsOverlapping(_map,mask_decal, solid_layer, position)){
                position.y -= 1.0f;
            }
        }
        if(velocity.y < 0.0f){
            position.y = std::ceil(position.y);
            while(IsOverlapping(_map,mask_decal, solid_layer, position)){
                position.y += 1.0f;
            }
        }

        velocity.y = 0.0f;
    }

    //SEMI SOLID

    if(IsOverlapping(_map,mask_decal, solid_layer, position, olc::RED) &&
        velocity.y > 0.0f &&
        !is_already_in_semi_solid){
        if(velocity.y > 0.0f){
            position.y = std::floor(position.y);
            while(IsOverlapping(_map,mask_decal, solid_layer, position, olc::RED)){
                position.y -= 1.0f;
            }
        }
        if(velocity.y < 0.0f){
            position.y = std::ceil(position.y);
            while(IsOverlapping(_map,mask_decal, solid_layer, position, olc::RED)){
                position.y += 1.0f;
            }
        }

        velocity.y = 0.0f;
    }
}

void
CellActor::AdjustUpSlope(CellMap* _map){
    //SOLID

    if(IsOverlapping(_map,mask_decal, solid_layer, position)){
        //Explanation
        //Upon colliding in what we presume to be the x-axis, we look back on our former position to see how Dummy interacts
        //from there with the terrain, pixel by pixel.
        //We start by flooring former_position.y to make sure Dummy is properly aligned with the grid in case he for some reason wouldn't be.
        //depending on velocity we do the same in the x-axis.
        former_position.y = std::floor(former_position.y);

        if(velocity.x > 0.0f){
            former_position.x = std::floor(former_position.x);
        }
        if(velocity.x < 0.0f){
            former_position.x = std::ceil(former_position.x);
        }

        if(velocity.x > 0.0f){
            //Explanation
            //Until former_position.x becomes our current position, we step in the direction of our velocity in the x-axis.
            //This works because Dummy's new position is on the same pixel as former_position.x + velocity.x
            while(std::floor(former_position.x) != std::floor(position.x)+1.0f){
                if(IsOverlappingHeight(_map, mask_decal, solid_layer, former_position) > int(former_position.y) + snap_up_range
                    && IsOverlappingHeight(_map, mask_decal, solid_layer, former_position) != former_position.y +
                    mask_decal->sprite->Size().y){

                    while(IsOverlapping(_map, mask_decal, solid_layer, former_position)){
                        former_position.y -= 1.0f;
                    }

                }

                former_position.x += 1.0f;
            }
            //if you're still in collision after moving +=1.0f, then you move up again
            //There is a possibility that Dummy entres another pixel upon the last step, so you need to readjust in the y-axis.
            if(IsOverlappingHeight(_map, mask_decal, solid_layer, former_position) > int(former_position.y) + snap_up_range){
                while(IsOverlapping(_map, mask_decal, solid_layer, former_position)){
                    former_position.y -= 1.0f;
                }
            }
        }

        if(velocity.x < 0.0f){
            while(former_position.x != std::floor(position.x)){

                if(IsOverlappingHeight(_map, mask_decal, solid_layer, former_position) > int(former_position.y) + snap_up_range
                    && IsOverlappingHeight(_map, mask_decal, solid_layer, former_position) != former_position.y +
                    mask_decal->sprite->Size().y){
                    while(IsOverlapping(_map, mask_decal, solid_layer, former_position)){
                        former_position.y -= 1.0f;
                    }

                }

                former_position.x -= 1.0f;
            }

            if(IsOverlappingHeight(_map, mask_decal, solid_layer, former_position) > int(former_position.y) + snap_up_range){
                while(IsOverlapping(_map, mask_decal, solid_layer, former_position)){
                    former_position.y -= 1.0f;
                }

            }
        }
    }

    //SEMI SOLID ADJUST_HEIGHT

    if(IsOverlapping(_map, mask_decal, solid_layer, position, olc::RED) && !is_already_in_semi_solid){
        former_position.y = std::floor(former_position.y);

        if(velocity.x > 0.0f){
            former_position.x = std::floor(former_position.x);
        }
        if(velocity.x < 0.0f){
            former_position.x = std::ceil(former_position.x);
        }

        if(velocity.x > 0.0f){

            while(std::floor(former_position.x) != std::floor(position.x)+1.0f){
                if(IsOverlappingHeight(_map, mask_decal, solid_layer, former_position, olc::RED) > int(former_position.y) + snap_up_range
                    && IsOverlappingHeight(_map, mask_decal, solid_layer, former_position, olc::RED) != former_position.y +
                    mask_decal->sprite->Size().y){

                    while(IsOverlapping(_map, mask_decal, solid_layer, former_position, olc::RED)){
                        former_position.y -= 1.0f;
                    }

                }

                former_position.x += 1.0f;
            }

            if(IsOverlappingHeight(_map, mask_decal, solid_layer, former_position, olc::RED) > int(former_position.y) + snap_up_range){
                while(IsOverlapping(_map, mask_decal, solid_layer, former_position, olc::RED)){
                    former_position.y -= 1.0f;
                }
            }
        }

        if(velocity.x < 0.0f){
            while(former_position.x != std::floor(position.x)){

                if(IsOverlappingHeight(_map, mask_decal, solid_layer, former_position, olc::RED) > int(former_position.y) + snap_up_range
                    && IsOverlappingHeight(_map, mask_decal, solid_layer, former_position, olc::RED) != former_position.y +
                    mask_decal->sprite->Size().y){
                    while(IsOverlapping(_map, mask_decal, solid_layer, former_position, olc::RED)){
                        former_position.y -= 1.0f;
                    }

                }

                former_position.x -= 1.0f;
            }

            if(IsOverlappingHeight(_map, mask_decal, solid_layer, former_position, olc::RED) > int(former_position.y) + snap_up_range){
                while(IsOverlapping(_map, mask_decal, solid_layer, former_position, olc::RED)){
                    former_position.y -= 1.0f;
                }

            }
        }
    }
    position.y = former_position.y;
}

void
CellActor::AdjustDownSlope(CellMap* _map){
    //HEIGHT ADJUSTMENT SNAP_TO_GROUND

    if(was_grounded == true && is_grounded == false && velocity.y > 0.0f){
        position.y = std::floor(position.y);
        if(HeightUntilGround(_map, mask_decal, solid_layer, position) < snap_to_ground){
            while(!IsOverlapping(_map, mask_decal, solid_layer, position)){

                position.y += 1.0f;

            }
            position.y -= 1.0f;
        }
    }

    //SEMI SOLID HEIGHT ADJUSTMENT SNAP_TO_GROUND
    if(was_grounded == true && is_grounded == false && velocity.y > 0.0f){
        position.y = std::floor(position.y);
        if(HeightUntilGround(_map, mask_decal, solid_layer, position, olc::RED) < snap_to_ground){
            while(!IsOverlapping(_map, mask_decal, solid_layer, position, olc::RED)){

                position.y += 1.0f;

            }
            position.y -= 1.0f;
        }
    }
}

void CellActor::Update(){}
void CellActor::Draw(Camera* _camera){}