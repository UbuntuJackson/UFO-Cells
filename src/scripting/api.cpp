#include "../../external/olcPixelGameEngine.h"
#include "../program/ufo_global.h"
#include "../ufo/collision_utils.h"
#include "../ufo/rect.h"
#include <string>
#include "api.h"
#include <iostream>

//game specific
#include "../../games/dummy_test/dummy_test_game.h"
#include "../../games/dummy_test/dummy.h"

namespace UfoAPI{
    void PrintFunction(std::string s){std::cout << s << std::endl;}
    void LoadDecal(std::string _path){}
    void DrawDecal(int _x, int _y, std::string _decal_key){}

    void DrawRectangleDecal(int x, int y, int w, int h, int r, int g, int b, int a){
        UfoGlobal::program.DrawRectDecal(olc::vf2d(x, y), olc::vf2d(w, h), olc::Pixel(r,g,b,a));
    }
    void FillRectangleDecal(int x, int y, int w, int h, int r, int g, int b, int a){
        UfoGlobal::program.FillRectDecal(olc::vf2d(x, y), olc::vf2d(w, h), olc::Pixel(r,g,b,a));
    }

    void DrawStringDecal(int x, int y, std::string _text, int r, int g, int b, int a, float _scale_x, float _scale_y){
        UfoGlobal::program.DrawStringDecal(olc::vf2d(x, y), _text, olc::Pixel(r,g,b,a), olc::vf2d(_scale_x, _scale_y));
    }

    //olc::HWButton GetKey(){}
    int GetMousePosX(){
        return UfoGlobal::program.GetMousePos().x;
    }
    int GetMousePosY(){
        return UfoGlobal::program.GetMousePos().y;
    }
    bool MouseLeftPressed(){
        return UfoGlobal::program.GetMouse(0).bPressed;
    }
    void GetMouseWheel(){}

    bool RectangleVsPoint(float rx, float ry, float rw, float rh, float px, float py){
        return RectVsPoint(Rect(olc::vf2d(rx, ry), olc::vf2d(rw, rh)), olc::vf2d(px, py));
    }

    //game control
    void Quit(){
        UfoGlobal::program.running = false;
    }

    void NewDummyTestGame(){
        DummyTestGame *game = new DummyTestGame();
    }
    void UpdateDummyTestGame(){
        UfoGlobal::program.game->game_state->Update();
    }
}