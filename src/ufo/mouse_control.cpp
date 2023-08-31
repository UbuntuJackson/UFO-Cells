#include "mouse_control.h"
#include "../../external/olcPixelGameEngine.h"
#include "game.h"

MouseControl::MouseControl(Game* _game): game{_game}, former_mouse_position{olc::vf2d(0.0f, 0.0f)}{}

int
MouseControl::GetDeltaMouseWheel(){
    return game->GetMouseWheel();
}
olc::vf2d MouseControl::GetDeltaMousePosition(){
    olc::vf2d delta_pos = game->GetMousePos() - former_mouse_position;
    former_mouse_position = game->GetMousePos();
    return delta_pos;
}

MouseControl::~MouseControl(){}