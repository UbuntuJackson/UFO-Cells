#ifndef ANIM_COMMON_H
#define ANIM_COMMON_H
#include "../../src/ufo/animation.h"
#include <string>
#include "../../external/olcPixelGameEngine.h"

class Game;

class AnimCommon : public Animation{
public:
    AnimCommon() = default;
    AnimCommon(Game* _game, std::string _sprite_sheet, olc::vf2d _frame_size, float _delta_frames);
};

#endif