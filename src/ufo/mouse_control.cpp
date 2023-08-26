#include "mouse_control.h"
#include "../../external/olcPixelGameEngine.h"
#include "../program/ufo_global.h"

MouseControl::MouseControl(): former_mouse_position{olc::vf2d(0.0f, 0.0f)}{}

int
MouseControl::GetDeltaMouseWheel(){
    return UfoGlobal::game->GetMouseWheel();
}
olc::vf2d MouseControl::GetDeltaMousePosition(){
    olc::vf2d delta_pos = UfoGlobal::game->GetMousePos() - former_mouse_position;
    former_mouse_position = UfoGlobal::game->GetMousePos();
    return delta_pos;
}

MouseControl::~MouseControl(){}