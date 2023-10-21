#include "squirrel_interface.h"
#include <string>
#include "../ufo/collision_utils.h"
#include "../ufo/game.h"

//SquirrelInterface::SquirrelInterface(Game *_game): game{_game}{}

void
SquirrelInterface::PrintFunction(std::string s){std::cout << s << std::endl;}
void LoadDecal(std::string _path){}
void DrawDecal(int _x, int _y, std::string _decal_key){}

void SquirrelInterface::DrawRectangleDecal(int x, int y, int w, int h, int r, int g, int b, int a){
    game->DrawRectDecal(olc::vf2d(x, y), olc::vf2d(w, h), olc::Pixel(r,g,b,a));
}
void SquirrelInterface::FillRectangleDecal(int x, int y, int w, int h, int r, int g, int b, int a){
    game->FillRectDecal(olc::vf2d(x, y), olc::vf2d(w, h), olc::Pixel(r,g,b,a));
}

void SquirrelInterface::DrawStringDecal(int x, int y, std::string _text, int r, int g, int b, int a, float _scale_x, float _scale_y){
    game->DrawStringDecal(olc::vf2d(x, y), _text, olc::Pixel(r,g,b,a), olc::vf2d(_scale_x, _scale_y));
}

/*void DrawMap(){
    game->cell_map.Draw();
}*/

//olc::HWButton GetKey(){}
int SquirrelInterface::GetMousePosX(){
    return game->GetMousePos().x;
}
int SquirrelInterface::GetMousePosY(){
    return game->GetMousePos().y;
}
bool SquirrelInterface::MouseLeftPressed(){
    return game->GetMouse(0).bPressed;
}
void SquirrelInterface::GetMouseWheel(){}

bool SquirrelInterface::RectangleVsPoint(float rx, float ry, float rw, float rh, float px, float py){
    return RectVsPoint(Rect(olc::vf2d(rx, ry), olc::vf2d(rw, rh)), olc::vf2d(px, py));
}

//game control
void SquirrelInterface::Quit(){
    game->running = false;
}

void SquirrelInterface::SetState(std::string _state, std::string _data){
    game->SetState(_state, _data);
}

std::string SquirrelInterface::GetStateData(){
    return game->game_state->GetData();
}