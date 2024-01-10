#include "button.h"
#include "camera.h"
#include "rect.h"
#include "collision_utils.h"
#include "../../external/olcPixelGameEngine.h"
#include "game.h"
Button::Button(Game* _game, olc::vf2d _position, olc::vf2d _size) : game{_game}, position{_position}, size{_size}{}

Button::Button(Game* _game, olc::vf2d _position, std::string _decal_neutral, std::string _decal_hover, std::string _decal_clicked) :
game{_game},
position{_position},
decal_neutral{_decal_neutral},
decal_hover{_decal_hover},
decal_clicked{_decal_clicked},
size{_game->asset_manager.GetDecal(_decal_neutral)->sprite->Size()}
{

}

bool
Button::Clicked(){
    if(RectVsPoint(Rect(position, size) ,game->GetMousePos()) && game->GetMouse(0).bPressed){
        return true;
    }
    return false;
}

bool
Button::Hover(){
    if(RectVsPoint(Rect(position, size), game->GetMousePos())){
        return true;
    }
    return false;
}

void
Button::Draw(Camera* _camera){
    if(Hover()){
        if(Clicked()) game->DrawDecal(position, game->asset_manager.GetDecal(decal_clicked));
        else game->DrawDecal(position, game->asset_manager.GetDecal(decal_hover));
    }
    else{
        game->DrawDecal(position, game->asset_manager.GetDecal(decal_neutral));
    }
}