#ifndef UFO_GLOBAL_H
#define UFO_GLOBAL_H

#include "../scripting_utils/squirrel_interface.h"
#include "../../external/olcPixelGameEngine.h"

namespace UfoGlobal{
    extern SquirrelInterface squirrel_interface;
    enum Direction{
        LEFT, RIGHT, UP, DOWN
    };
    extern const RED = olc::RED;
    extern const ORANGE = olc::Pixel(255,136,0);
    extern const YELLOW = olc::Pixel(255,221,0);
    extern const LEMON = olc::Pixel(255, 221, 170);
}
#endif

