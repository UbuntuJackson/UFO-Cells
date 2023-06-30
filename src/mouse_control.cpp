#include "mouse_control.h"
#include "../external/olcPixelGameEngine.h"
#include "program.h"

MouseControl::MouseControl(Program *_program): program{_program}, former_mouse_position{_program->GetMousePos()}{}

int
MouseControl::GetDeltaMouseWheel(){
    return program->GetMouseWheel();
}
olc::vf2d MouseControl::GetDeltaMousePosition(){
    olc::vf2d delta_pos = program->GetMousePos() - former_mouse_position;
    former_mouse_position = program->GetMousePos();
    return delta_pos;
}

MouseControl::~MouseControl(){}