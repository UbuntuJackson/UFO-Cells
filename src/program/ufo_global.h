#ifndef UFO_GLOBAL_H
#define UFO_GLOBAL_H

#include "../scripting_utils/squirrel_interface.h"

namespace UfoGlobal{
    extern SquirrelInterface squirrel_interface;
    enum Direction{
        LEFT, RIGHT, UP, DOWN
    };
}
#endif

