
#include "rect.h"
#include "../../external/olcPixelGameEngine.h"

bool
RectVsRect(Rect _rect_1, Rect _rect_2){
    if (
        (_rect_1.position.x > (_rect_2.position.x + _rect_2.size.x)) || // is the left side greater than the other rect's right side?
        ((_rect_1.position.x + _rect_1.size.x) < _rect_2.position.x) ||       // is the right side less than the other rect's left side?
        (_rect_1.position.y > (_rect_2.position.y + _rect_2.size.y)) || // is the lower side greater than the other rect's upper side?
        ((_rect_1.position.y + _rect_1.size.y) < _rect_2.position.y))         // is the upper side less than the other rect's lower side?
    {
        return false;
    }
    return true;
}

bool
RectVsPoint(Rect _rect, olc::vf2d _point){
    if (_point.x < _rect.position.x ||
        _point.x > _rect.position.x + _rect.size.x ||
        _point.y < _rect.position.y ||
        _point.y > _rect.position.y + _rect.size.y
        )         // is the upper side less than the other rect's lower side?
    {
        return false;
    }
    return true;
}