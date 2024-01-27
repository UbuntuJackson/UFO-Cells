#ifndef COLLISION_DATA_H
#define COLLISION_DATA_H
#include "../../external/olcPixelGameEngine.h"
struct CollisionData{
    float collision_time;
    float other_collision_time;
    olc::vf2d intersection_point;
    bool is_hit = false;
};

#endif