#ifndef RECT_2_H
#define RECT_2_H

#include "../../external/olcPixelGameEngine.h"

class Rect{
public:
    olc::vf2d position;
    olc::vf2d size;
    int id;
    Rect() = default;
    Rect(olc::vf2d _position, olc::vf2d _size);
};

#endif