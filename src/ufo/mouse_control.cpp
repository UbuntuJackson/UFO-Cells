#include "mouse_control.h"
#include "../../external/olcPixelGameEngine.h"
#include "../program/program.h"
#include "../program/ufo_global.h"

MouseControl::MouseControl(): former_mouse_position{UfoGlobal::program.GetMousePos()}{}

int
MouseControl::GetDeltaMouseWheel(){
    return UfoGlobal::program.GetMouseWheel();
}
olc::vf2d MouseControl::GetDeltaMousePosition(){
    olc::vf2d delta_pos = UfoGlobal::program.GetMousePos() - former_mouse_position;
    former_mouse_position = UfoGlobal::program.GetMousePos();
    return delta_pos;
}

MouseControl::~MouseControl(){}