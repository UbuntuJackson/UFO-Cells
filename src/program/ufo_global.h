#ifndef UFO_GLOBAL_H
#define UFO_GLOBAL_H

#include "../scripting_utils/squirrel_interface.h"
#include "../../external/olcPixelGameEngine.h"

namespace UfoGlobal{
    extern SquirrelInterface squirrel_interface;
    enum Direction{
        LEFT, RIGHT, UP, DOWN
    };
    const olc::Pixel RED = olc::RED;
    const olc::Pixel ORANGE = olc::Pixel(255,136,0);
    const olc::Pixel YELLOW = olc::Pixel(255,221,0);
    const olc::Pixel LEMON = olc::Pixel(255, 221, 170);
}
#endif

