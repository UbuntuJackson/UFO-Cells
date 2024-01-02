#ifndef BUTTON_H
#define BUTTON_H
#include "rect.h"

class Game;

class Button{
public:
    int anim_default;
    int anim_hover;
    int anim_clicked;
    Game* game;
    Rect rect;
    Button(Game* _game, float _x, float _y, float _w, float _h);
    bool Clicked();
    bool Hover();
    void Draw(Camera* _camera);
};

#endif