#ifndef MOUSE_CONTROL_H
#define MOUSE_CONTROL_H
#include "../../external/olcPixelGameEngine.h"

class Game;

class MouseControl{
public:
    Game* game;
    MouseControl(Game* _game);
    ~MouseControl();
    olc::vf2d former_mouse_position;
    //olc::Decal cursor_decal;
    int GetDeltaMouseWheel();
    olc::vf2d GetDeltaMousePosition();
    
};

#endif