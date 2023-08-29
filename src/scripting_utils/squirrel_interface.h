#ifndef SQUIRRE_INTERFACE_H
#define SQUIRRE_INTERFACE_H

#include "../../external/olcPixelGameEngine.h"
#include "../ufo/game.h"
#include "../ufo/rect.h"
#include "../ufo/collision_utils.h"

class SquirrelInterface{
public:
    Game *game;
    SquirrelInterface() = default;
    void PrintFunction(std::string s);
    void LoadDecal(std::string _path);
    void DrawDecal(int _x, int _y, std::string _decal_key);

    void DrawRectangleDecal(int x, int y, int w, int h, int r, int g, int b, int a);
    void FillRectangleDecal(int x, int y, int w, int h, int r, int g, int b, int a);
    void DrawStringDecal(int x, int y, std::string _text, int r, int g, int b, int a, float _scale_x, float _scale_y);

    //olc::HWButton GetKey(){}
    int GetMousePosX();
    int GetMousePosY();
    bool MouseLeftPressed();
    void GetMouseWheel(){}

    bool RectangleVsPoint(float rx, float ry, float rw, float rh, float px, float py){
        return RectVsPoint(Rect(olc::vf2d(rx, ry), olc::vf2d(rw, rh)), olc::vf2d(px, py));
    }

    //game control
    void Quit(){
        game->running = false;
    }

    void SetState(std::string _state, std::string _data){
        game->SetState(_state, _data);
    }

    std::string GetStateData(){
        return game->game_state->GetData();
    }

};




#endif