#ifndef ENTITY_H
#define ENTITY_H
#include "olcPixelGameEngine.h"

class Program;

class Entity{
public:
    olc::vf2d position;
    olc::vf2d velocity;
    olc::vf2d size;
    Program *program;
    bool is_grounded;
    bool was_grounded;
    int snap_to_ground;
    
    Entity(Program *_program,olc::vf2d _position);
    void Advance(float _dest_x, float _dest_y);
    bool IsOverlapping();
    int IsOverlappingHeight();
    int HeightUntilGround();
    void Update();
    void Draw();
};

#endif