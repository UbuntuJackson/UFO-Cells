#include "anim_snowman.h"
#include "../../src/ufo/game.h"
#include <string>
#include "../../src/ufo/animation.h"

AnimSnowman::AnimSnowman(Game* _game, std::string _sprite_sheet, olc::vf2d _frame_size): Animation(_game){
    sprite_sheet = _sprite_sheet;
    frame_size = _frame_size;
    delta_frames = 0.09f;
    current_anim = {3, 4, 5, 6,7,8,9,10};
    if(current_anim.size() < 1) std::cout << this << ": current_anim is empty" << std::endl;
    Play();
}

void
AnimSnowman::UpdateStateLogic(){
    std::cout << "updatestatelogic" << std::endl;
    if(frame_count > 10.0f){
        //Stop();
    }
}