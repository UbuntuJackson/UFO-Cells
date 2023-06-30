#ifndef MOUSE_CONTROL_H
#define MOUSE_CONTROL_H
#include "../external/olcPixelGameEngine.h"

class Program;

class MouseControl{
public:
    MouseControl() = default;
    MouseControl(Program *_program);
    ~MouseControl();
    Program* program;
    olc::vf2d former_mouse_position;
    //olc::Decal cursor_decal;
    int GetDeltaMouseWheel();
    olc::vf2d GetDeltaMousePosition();
    
};

#endif