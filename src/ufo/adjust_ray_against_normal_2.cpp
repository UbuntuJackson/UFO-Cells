#include "ray2.h"

Ray2
AdjustRayAgainstNormal(Ray2& _ray, Ray2& _other_ray){
    /*float useful_intersection_time = _ray.VsOtherRay(_other_ray).collision_time; 

    olc::vf2d normal_intersection = Ray2(_ray.Start(), _other_ray.Normal()).VsOtherRay(_other_ray);

    olc::vf2d portion_to_keep = normal_intersection - _ray.Start();

    olc::vf2d portion_full = portion_to_keep * 1.0f/useful_intersection_time;

    return _ray.Size() - (portion_full - portion_to_keep);*/

    Ray2 velocity_end_against_normal = Ray2(_ray.End(), _other_ray.Normal() * -1.0f);
    olc::vf2d new_end = velocity_end_against_normal.VsOtherRay(_other_ray).intersection_point;
    return Ray2(_ray.Start(), new_end);

}