#include "math_misc.h"
#include <cmath>
#include "../../external/olcPixelGameEngine.h"

namespace ufo{
namespace math_ex{

float Sign(float num){
    if(std::abs(num) < 0.01f) return 0.0f;
    else if(num > 0.0f) return 1.0f;
    return -1.0f;
    
}

float Distance2(olc::vf2d _p0, olc::vf2d _p1){
    return std::sqrt((_p0-_p1).x*(_p0-_p1).x+(_p0-_p1).y*(_p0-_p1).y);
}

}
}