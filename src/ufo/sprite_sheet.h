#ifndef SPRITE_SHEET_H
#define SPRITE_SHEET_H
#include <vector>
#include "../../external/olcPixelGameEngine.h"

class SpriteSheet{
public:
    olc::vf2d sprite_size;
    std::vector<olc::vf2d> index_array;
    SpriteSheet() = default;
    void MakeIndexVector(olc::vf2d _sprite_size);
};

#endif