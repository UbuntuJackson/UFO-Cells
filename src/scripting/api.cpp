#include "../external/olcPixelGameEngine.h"
#include "../program/ufo_global.h"
#include <string>
#include "api.h"
#include <iostream>

namespace UfoAPI{
    void TestFunction(){std::cout << "hello world" << std::endl;}
    void LoadDecal(std::string _path){}
    void DrawDecal(int _x, int _y, std::string _decal_key){}
    //olc::HWButton GetKey(){}
    void GetMousePos(){}
    void GetMouseWheel(){}
}