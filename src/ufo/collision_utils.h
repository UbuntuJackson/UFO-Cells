#ifndef COLLISION_UTILS_H
#define COLLISION_UTILS_H
#include "rect.h"
#include "collision_utils.h"
#include "../../external/olcPixelGameEngine.h"


bool
RectVsRect(Rect _rect_1, Rect _rect_2);

bool
RectVsPoint(Rect _rect, olc::vf2d _point);

#endif