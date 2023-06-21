#include "misc_math.h"
#include <cmath>

float Sign(float num){
    if(std::abs(num) < 0.01f) return 0.0f;
    else if(num > 0.0f) return 1.0f;
    return -1.0f;
    
}