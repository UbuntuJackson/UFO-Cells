//#ifndef API_H
#ifndef SCRIPTING_API
#include "../external/olcPixelGameEngine.h"
#include "../program/ufo_global.h"
#include <string>
#endif

namespace UfoAPI{
    void TestFunction();
    void LoadDecal(std::string _path);
    void DrawDecal(int _x, int _y, std::string _decal_key);
    //olc::HWButton GetKey(){}
    void GetMousePos();
    void GetMouseWheel();
}

//#endif API_H
