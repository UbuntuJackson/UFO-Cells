#include "cell_actor.h"
#include "colour_utils.h"
#include "../program/program.h"
#include <string>
#include "../program/ufo_global.h"
#include "../../external/olcPixelGameEngine.h"
#include <iostream>

CellActor::CellActor(olc::vf2d _position) :
    position{_position},
    is_grounded{false},
    was_grounded{false},
    snap_to_ground{6},
    snap_up_range{16}
{
}

CellActor::CellActor(olc::vf2d _position, std::string _mask) :
    position{_position},
    mask{_mask},
    is_grounded{false},
    was_grounded{false},
    snap_to_ground{6},
    snap_up_range{16}
{
}

CellActor::~CellActor(){}

int
CellActor::IsOverlappingHeight(olc::Decal *_decal, std::string _layer, olc::vf2d _position, olc::Pixel _colour){

    olc::Decal* collision_layer = UfoGlobal::program.cell_map.map_decals[_layer];

    for(int y = _position.y; y < _position.y + _decal->sprite->Size().y; y++){
        for(int x = _position.x; x < _position.x + _decal->sprite->Size().x; x++){
            if(CompareColour(_decal->sprite->GetPixel(x- _position.x, y- _position.y), olc::WHITE)
                && CompareColour(collision_layer->sprite->GetPixel(x, y), _colour) //I'm gonna need a downcast or access the name from the asset manager
            ){
                return y;
            }
        }
    }
    return position.y + _decal->sprite->Size().y;
}

//HeightUntilGround
//Used to make platforming type actors snap to ground as if they are walking down a slope, or stairs.
//Do a comparison between the value returned by this function and snap_to_ground
int
CellActor::HeightUntilGround(olc::Decal *_decal, std::string _layer, olc::vf2d _position, olc::Pixel _colour){

    olc::Decal* collision_layer = UfoGlobal::program.cell_map.map_decals[_layer];

    for(int y = _position.y + _decal->sprite->Size().y; y < _position.y + _decal->sprite->Size().y + snap_to_ground; y++){
        for(int x = _position.x; x < _position.x + _decal->sprite->Size().x; x++){
            if(CompareColour(collision_layer->sprite->GetPixel(x,y), _colour)){

                //Difference between player bottom and highest collision cell
                return y -(_position.y + _decal->sprite->Size().y);
            }
        }
    }
    //This is returned to consider it a non-snap case, too much space between actor and ground
    return snap_to_ground;
}

//should be IsOverlapping(olc::Decal *_decal, olc::vf2d _position, std::string _other_decal, olc::vf2d _other_position, olc::Pixel _colour)
//can make a function that iterates through actor layers and makes use of this function
bool
CellActor::IsOverlapping(olc::Decal *_decal, std::string _layer, olc::vf2d _position, olc::Pixel _colour){

    olc::Decal* collision_layer = UfoGlobal::program.cell_map.map_decals[_layer];

    for(int y = _position.y; y < _position.y + _decal->sprite->Size().y; y++){
        for(int x = _position.x; x < _position.x + _decal->sprite->Size().x; x++){
            if(CompareColour(_decal->sprite->GetPixel(x- _position.x, y- _position.y), olc::WHITE)
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

    for(int y = _position.y; y < _position.y + _decal->sprite->Size().y; y++){
        for(int x = _position.x; x < _position.x + _decal->sprite->Size().x; x++){
            if(CompareColour(_decal->sprite->GetPixel(x- _position.x, y- _position.y), olc::WHITE)
                && CompareColour(_other_decal->sprite->GetPixel(x - _other_position.x, y - _other_position.y), _colour)
            ){
                return true;
            }
        }
    }
    return false;
}

void CellActor::Update(){}
void CellActor::Draw(){}