#include "ray2.h"
#include "line_vs_line_2d.h"

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

float
Ray2::LineVsLine(Ray2 _other_ray){
    
    return LinearAlgebra::LineVsLine(Ray2(p0,p1), _other_ray);

}