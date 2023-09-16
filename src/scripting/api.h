//#ifndef API_H
#ifndef SCRIPTING_API
#include "../../external/olcPixelGameEngine.h"
#include "../program/ufo_global.h"
#include <string>
#endif

namespace UfoAPI{
    void PrintFunction(std::string s);
    void LoadDecal(std::string _path);
    void DrawDecal(int _x, int _y, std::string _decal_key);
    void DrawRectangleDecal(int x, int y, int w, int h, int r, int g, int b, int a);
    void FillRectangleDecal(int x, int y, int w, int h, int r, int g, int b, int a);
    void DrawStringDecal(int x, int y, std::string _text, int r, int g, int b, int a, float _scale_x, float _scale_y);
    void DrawMap();
    //olc::HWButton GetKey(){}
    int GetMousePosX();
    int GetMousePosY();
    bool MouseLeftPressed();
    void GetMouseWheel();
    bool RectangleVsPoint(float rx, float ry, float rw, float rh, float px, float py);
    //Game control
    void Quit();
    void SetState(std::string _state, std::string _data);
    std::string GetStateData();
    //Game-specific
}

//#endif API_H
