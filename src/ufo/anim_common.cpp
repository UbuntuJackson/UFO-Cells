#include "anim_common.h"
#include "../../src/ufo/game.h"
#include <string>
#include "../../src/ufo/animation.h"

AnimCommon::AnimCommon(Game* _game, std::string _sprite_sheet, olc::vf2d _frame_size, float _delta_frames): Animation(_game){
    sprite_sheet = _sprite_sheet;
    frame_size = _frame_size;
    delta_frames = _delta_frames;
    current_anim = {2, 2, 3, 1, 6, 4, 5};
    if(current_anim.size() < 1) std::cout << this << ": current_anim is empty" << std::endl;
    Play();
}