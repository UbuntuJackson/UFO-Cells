#ifndef CELL_ACTOR_H
#define CELL_ACTOR_H
#include "../../external/olcPixelGameEngine.h"

class Program;

class CellActor{
public:
    olc::vf2d position;
    olc::vf2d velocity;
    olc::vf2d size;
    std::string mask;
    bool is_grounded;
    bool was_grounded;
    int snap_to_ground;
    int snap_up_range;

    int draw_layer = 2;

    CellActor(olc::vf2d _position);
    ~CellActor();
    bool IsOverlapping(olc::Decal *_decal, std::string _layer, olc::vf2d _position, olc::Pixel _colour = olc::WHITE);
    int IsOverlappingHeight(olc::Decal *_decal, std::string _layer, olc::vf2d _position, olc::Pixel _colour = olc::WHITE);
    int HeightUntilGround(olc::Decal *_decal, std::string _layer, olc::vf2d _position, olc::Pixel _colour = olc::WHITE);
    bool IsOverlappingOtherDecal(olc::Decal *_decal, olc::vf2d _position, olc::Decal *_other_decal, olc::vf2d _other_position, olc::Pixel _colour);

    virtual void Update();
    virtual void Draw();
};

#endif