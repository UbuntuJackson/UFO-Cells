#include "../external/olcPixelGameEngine.h"
#include "../program/ufo_global.h"
#include <string>
#include "api.h"
#include <iostream>

//game specific
#include "../../games/dummy_test/dummy_test_game.h"
#include "../../games/dummy_test/dummy.h"

namespace UfoAPI{
    void TestFunction(){std::cout << "hello world" << std::endl;}
    void LoadDecal(std::string _path){}
    void DrawDecal(int _x, int _y, std::string _decal_key){}
    //olc::HWButton GetKey(){}
    void GetMousePos(){}
    void GetMouseWheel(){}
    void NewDummyTestGame(){
        DummyTestGame *game = new DummyTestGame();
        std::cout << &UfoGlobal::program << std::endl;
    }
    void UpdateDummyTestGame(){
        UfoGlobal::program.game->game_state->Update();
    }
}