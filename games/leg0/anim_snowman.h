#ifndef ANIM_SNOWMAN_H
#define ANIM_SNOWMAN_H
#include "../../src/ufo/animation.h"
#include <string>
#include "../../external/olcPixelGameEngine.h"

class Game;

class AnimSnowman : public Animation{
public:
    AnimSnowman() = default;
    AnimSnowman(Game* _game, std::string _sprite_sheet, olc::vf2d _frame_size);
    void UpdateStateLogic();
};

#endif