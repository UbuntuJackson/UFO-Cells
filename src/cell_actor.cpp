#include "cell_actor.h"
#include "colour_utils.h"
#include "program.h"
#include <string>

CellActor::CellActor(Program *_program,olc::vf2d _position) :
    program{_program},
    position{_position},
    is_grounded{false},
    was_grounded{false},
    snap_to_ground{10},
    snap_up_range{22}
{
}

CellActor::~CellActor(){
    //delete mask_decal;
    //std::cout << "Cell actor's destructor" << std::endl;
}

int
CellActor::IsOverlappingHeight(olc::Decal *_decal, std::string _layer, olc::vf2d _position){

    olc::Decal* collision_layer = program->cell_map.collision_layers[_layer];

    for(int y = _position.y; y < _position.y + _decal->sprite->Size().y; y++){
        for(int x = _position.x; x < _position.x + _decal->sprite->Size().x; x++){
            if(CompareColour(_decal->sprite->GetPixel(x- _position.x, y- _position.y), olc::WHITE)
                && CompareColour(collision_layer->sprite->GetPixel(x, y), olc::WHITE)
            ){
                return y;
            }
        }
    }
    return position.y + _decal->sprite->Size().y;
}

int
CellActor::HeightUntilGround(olc::Decal *_decal, std::string _layer, olc::vf2d _position){

    olc::Decal* collision_layer = program->cell_map.collision_layers[_layer];

    for(int y = _position.y + _decal->sprite->Size().y; y < _position.y + _decal->sprite->Size().y + snap_to_ground; y++){
        for(int x = _position.x; x < _position.x + _decal->sprite->Size().x; x++){
            if(CompareColour(collision_layer->sprite->GetPixel(x,y), olc::WHITE)){
                return y -(_position.y + _decal->sprite->Size().y);
            }
        }
    }
    return snap_to_ground;
}

bool
CellActor::IsOverlapping(olc::Decal *_decal, std::string _layer, olc::vf2d _position){

    olc::Decal* collision_layer = program->cell_map.collision_layers[_layer];

    for(int y = _position.y; y < _position.y + _decal->sprite->Size().y; y++){
        for(int x = _position.x; x < _position.x + _decal->sprite->Size().x; x++){
            if(CompareColour(_decal->sprite->GetPixel(x- _position.x, y- _position.y), olc::WHITE)
                && CompareColour(collision_layer->sprite->GetPixel(x, y), olc::WHITE)
            ){
                return true;
            }
        }
    }
    return false;
}

void
CellActor::Update(){}

void
CellActor::Draw(){}