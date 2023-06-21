#ifndef RECTANGLE_2_H
#define RECTANGLE_2_H

#include "olcPixelGameEngine.h"

class Rect{
public:
    olc::vf2d position;
    olc::vf2d size;
    int id;
    Rect(olc::vf2d _position, olc::vf2d _size);
};

#endif