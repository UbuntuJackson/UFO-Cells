#include "../external/olcPixelGameEngine.h"
#include "../program/ufo_global.h"
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
    void NewDummyTestGame(){
        DummyTestGame *game = new DummyTestGame();
    }
    void UpdateDummyTestGame(){
        UfoGlobal::program.game->game_state->Update();
    }
}