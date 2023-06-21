#ifndef COLOUR_UTILS
#define COLOUR_UTILS

#include "olcPixelGameEngine.h"

bool CompareColour(olc::Pixel colour_a, olc::Pixel colour_b);
void RemoveCell(int x, int y, olc::Sprite *sprmap, olc::Sprite *sprcollisionMap);

#endif