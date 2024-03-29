#ifndef RAY_2_H
#define RAY_2_H

#include "../../external/olcPixelGameEngine.h"
#include "collision_data.h"

class Ray2{
public:
    olc::vf2d p0;
    olc::vf2d p1;
    olc::vf2d Start();
    olc::vf2d End();
    olc::vf2d Size();
    Ray2() = default;
    Ray2(olc::vf2d _p0, olc::vf2d _p1);
    CollisionData VsOtherRay(Ray2 &_other_ray);
    olc::vf2d Normal();
};

#endif