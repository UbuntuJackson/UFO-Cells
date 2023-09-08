#include "anim_snowman.h"
#include "../../src/ufo/game.h"
#include <string>
#include "../../src/ufo/animation.h"

AnimSnowman::AnimSnowman(Game* _game, std::string _sprite_sheet, olc::vf2d _frame_size): Animation(_game, _sprite_sheet, _frame_size){
    Play();
}