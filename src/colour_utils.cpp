#include "olcPixelGameEngine.h"

bool CompareColour(olc::Pixel colour_a, olc::Pixel colour_b){
    if(colour_a.r == colour_b.r && colour_a.g == colour_b.g && colour_a.b == colour_b.b &&
        colour_a.a == colour_b.a
    ){
        return true;
    }
    return false;
}

void RemoveCell(int x, int y, olc::Sprite *sprmap, olc::Sprite *sprcollisionMap){
    sprmap -> SetPixel(x, y, olc::Pixel(0, 0, 0, 0));
}