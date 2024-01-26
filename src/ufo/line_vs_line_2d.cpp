#include "ray2.h"

namespace LinearAlgebra{
    float LineVsLine(Ray2 _v, Ray2 _w){
        float s;
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

        s = (_w.p0.y + (_w.Size().y / _w.Size().x) * _v.p0.x - (_w.Size().y / _w.Size().x) * _w.p0.x) / (_v.p0.y + _v.Size().y - (_w.Size().y / _w.Size().x) * _v.Size().x);
        
        return s;
    }    

}