#include "ray_vs_ray_2.h"
#include "collision_data.h"
#include "ray2.h"

namespace LinearAlgebra{

CollisionData
DynamicCircleVsRay(DynamicCircle& _circle, Ray2 _ray){
    olc::vf2d max_distance_to_ray = _circle.radius * _ray.Normal();
    Ray2 new_ray = Ray2(_ray - max_distance_to_ray);

    return _circle.velocity.VsOtherRay();
}

}