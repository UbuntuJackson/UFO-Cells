#ifndef BUTTON_H
#define BUTTON_H
#include "rect.h"
#include "../../external/olcPixelGameEngine.h"
class Game;
class Camera;

class Button{
public:
    int anim_default;
    int anim_hover;
    int anim_clicked;
    Game* game;
    std::string decal_neutral;
    std::string decal_hover;
    std::string decal_clicked;
    olc::vf2d position;
    olc::vf2d size;
    Button() = default;
    Button(Game* _game, olc::vf2d _position, olc::vf2d _size);
    Button(Game* _game, olc::vf2d _position, std::string _decal_neutral, std::string _decal_hover, std::string _decal_clicked);
    bool Clicked();
    bool Hover();
    void Draw(Camera* _camera);
};

#endif