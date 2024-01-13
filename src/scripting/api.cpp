#include "../../external/olcPixelGameEngine.h"
#include "../program/ufo_global.h"
#include "../ufo/collision_utils.h"
#include "../ufo/rect.h"
#include <string>
#include "api.h"
#include <iostream>

namespace UfoAPI{
    void PrintFunction(std::string s){std::cout << s << std::endl;}
    void LoadDecal(std::string _path){}
    void DrawDecal(int _x, int _y, std::string _decal_key){}

    void DrawRectangleDecal(int x, int y, int w, int h, int r, int g, int b, int a){
        UfoGlobal::squirrel_interface.game->DrawRectDecal(olc::vf2d(x, y), olc::vf2d(w, h), olc::Pixel(r,g,b,a));
    }
    void FillRectangleDecal(int x, int y, int w, int h, int r, int g, int b, int a){
        UfoGlobal::squirrel_interface.game->FillRectDecal(olc::vf2d(x, y), olc::vf2d(w, h), olc::Pixel(r,g,b,a));
    }

    void DrawStringDecal(int x, int y, std::string _text, int r, int g, int b, int a, float _scale_x, float _scale_y){
        UfoGlobal::squirrel_interface.game->DrawStringDecal(olc::vf2d(x, y), _text, olc::Pixel(r,g,b,a), olc::vf2d(_scale_x, _scale_y));
    }

    void DrawMap(){
        //UfoGlobal::squirrel_interface.game->cell_map.Draw();
    }

    //olc::HWButton GetKey(){}
    int GetMousePosX(){
        return UfoGlobal::squirrel_interface.game->GetMousePos().x;
    }
    int GetMousePosY(){
        return UfoGlobal::squirrel_interface.game->GetMousePos().y;
    }
    bool MouseLeftPressed(){
        return UfoGlobal::squirrel_interface.game->GetMouse(0).bPressed;
    }
    void GetMouseWheel(){}

    bool RectangleVsPoint(float rx, float ry, float rw, float rh, float px, float py){
        return RectVsPoint(Rect(olc::vf2d(rx, ry), olc::vf2d(rw, rh)), olc::vf2d(px, py));
    }

    //game control
    void Quit(){
        UfoGlobal::squirrel_interface.game->running = false;
    }
}