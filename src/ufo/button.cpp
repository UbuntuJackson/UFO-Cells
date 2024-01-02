#include "button.h"
#include "camera.h"
#include "rect.h"
#include "collision_utils.h"
#include "../../external/olcPixelGameEngine.h"
#include "game.h"
Button::Button(Game* _game, float _x, float _y, float _w, float _h) : game{_game}, rect(olc::vf2d( _x, _y), olc::vf2d(_w, _h)){}

bool
Button::Clicked(){
    if(RectVsPoint(rect ,game->GetMousePos()) && game->GetMouse(0).bPressed){
        return true;
    }
    return false;
}

bool
Button::Hover(){
    if(RectVsPoint(rect, game->GetMousePos())){
        return true;
    }
    return false;
}

void
Button::Draw(Camera* _camera){

}