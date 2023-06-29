#include "mouse_control.h"
#include "olcPixelGameEngine.h"
#include "program.h"

MouseControl::MouseControl(Program *_program): program{_program}, former_mouse_position{_program->GetMousePos()}{}

int
MouseControl::GetDeltaMouseWheel(){
    return program->GetMouseWheel();
}
olc::vf2d MouseControl::GetDeltaMousePosition(){
    return program->GetMousePos() - former_mouse_position;
    former_mouse_position = program->GetMousePos();
}

MouseControl::~MouseControl(){}