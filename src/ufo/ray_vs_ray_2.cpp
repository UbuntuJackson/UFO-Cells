#include "ray2.h"
#include "ray_vs_ray_2.h"
#include "collision_data.h"
namespace LinearAlgebra{
    CollisionData RayVsRay(Ray2 _v, Ray2 _w){
        float collision_time;
        float collision_time_other;
        //float t;
        //_v.p0.x + _v.size().x * s = _w.p0.x + _w.size().x * t
        
        //solve for t
        //t = (_v.p0.x + _v.size().x * s - _w.p0.x) / _w.size().x    

        //_v.p0.y + _v.size().y * s = _w.p0.y + _w.size().y * t

        //solve for s

        //_v.p0.y + _v.size().y * s = _w.p0.y + (_w.size().y / _w.size().x) * (_v.p0.x + _v.size().x * s - _w.p0.x)

        //_v.p0.y + _v.size().y * s = _w.p0.y + (_w.size().y / _w.size().x) * _v.p0.x + (_w.size().y / _w.size().x) * _v.size().x * s - (_w.size().y / _w.size().x) * _w.p0.x

        //_v.p0.y + _v.size().y * s - (_w.size().y / _w.size().x) * _v.size().x * s = _w.p0.y + (_w.size().y / _w.size().x) * _v.p0.x - (_w.size().y / _w.size().x) * _w.p0.x

        //(_v.p0.y + _v.size().y - (_w.size().y / _w.size().x) * _v.size().x) * s = _w.p0.y + (_w.size().y / _w.size().x) * _v.p0.x - (_w.size().y / _w.size().x) * _w.p0.x

        collision_time = (_w.p0.y + (_w.Size().y / _w.Size().x) * _v.p0.x - (_w.Size().y / _w.Size().x) * _w.p0.x) / (_v.p0.y + _v.Size().y - (_w.Size().y / _w.Size().x) * _v.Size().x);
        
        float collision_time_other = LinearAlgebra::RayVsRay(_w, _v).collision_time;
        
        olc::vf2d intersection_point = _v.Start() + _v.Size() * collision_time;
        
        bool hit_succeed = false;
        
        if(collision_time < 0.0f || collision_time > 1.0f){
            hit_succeed = true;
        }

        return CollisionData{
            collision_time,
            collision_time_other,
            intersection_point,
            hit_succeed
        };
    }    

}