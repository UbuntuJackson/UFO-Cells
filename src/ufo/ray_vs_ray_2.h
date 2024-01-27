#ifndef RAY_VS_RAY_2_H
#define RAY_VS_RAY_2_H

#include "collision_data.h"
class Ray2;

namespace LinearAlgebra{
    CollisionData RayVsRay(Ray2& _v, Ray2& _w);
}

#endif