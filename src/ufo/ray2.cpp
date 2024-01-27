#include "ray2.h"
#include "ray_vs_ray_2.h"
#include "collision_data.h"
Ray2::Ray2(olc::vf2d _p0, olc::vf2d _p1) : p0{_p0}, p1{_p1}{}

olc::vf2d
Ray2::Start(){
    return p0;
}

olc::vf2d
Ray2::End(){
    return p1;
}

olc::vf2d
Ray2::Size(){
    return p1 - p0;
}

CollisionData
Ray2::VsOtherRay(Ray2& _other_ray){
    
    return LinearAlgebra::RayVsRay(*this, _other_ray);

}