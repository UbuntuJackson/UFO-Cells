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

CellActor::~CellActor(){}

int
CellActor::IsOverlappingHeight(olc::Decal *_decal, std::string _layer, olc::vf2d _position, olc::Pixel _colour){

    olc::Decal* collision_layer = UfoGlobal::program.cell_map.map_decals[_layer];

    for(int y = _position.y; y < _position.y + _decal->sprite->Size().y; y++){
        for(int x = _position.x; x < _position.x + _decal->sprite->Size().x; x++){
            if(CompareColour(_decal->sprite->GetPixel(x- _position.x, y- _position.y), olc::WHITE)
                && CompareColour(collision_layer->sprite->GetPixel(x, y), _colour)
            ){
                return y;
            }
        }
    }
    return position.y + _decal->sprite->Size().y;
}

int
CellActor::HeightUntilGround(olc::Decal *_decal, std::string _layer, olc::vf2d _position, olc::Pixel _colour){

    olc::Decal* collision_layer = UfoGlobal::program.cell_map.map_decals[_layer];

    for(int y = _position.y + _decal->sprite->Size().y; y < _position.y + _decal->sprite->Size().y + snap_to_ground; y++){
        for(int x = _position.x; x < _position.x + _decal->sprite->Size().x; x++){
            if(CompareColour(collision_layer->sprite->GetPixel(x,y), _colour)){
                return y -(_position.y + _decal->sprite->Size().y);
            }
        }
    }
    return snap_to_ground;
}

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

void CellActor::Update(){}
void CellActor::Draw(){}