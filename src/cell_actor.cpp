#include "cell_actor.h"
#include "colour_utils.h"
#include "program.h"

CellActor::CellActor(Program *_program,olc::vf2d _position) :
    program{_program},
    position{_position},
    is_grounded{false},
    was_grounded{false},
    snap_to_ground{8},
    snap_up_range{24}
{
}

int
CellActor::IsOverlappingHeight(olc::Decal *_decal){
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
CellActor::HeightUntilGround(olc::Decal *_decal){
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
CellActor::IsOverlapping(olc::Decal *_decal){
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