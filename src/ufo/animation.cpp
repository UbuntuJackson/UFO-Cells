#include "animation.h"
#include "camera.h"
#include "rect.h"
#include "game.h"

Animation::Animation(Game* _game, std::string _sprite_sheet, olc::vf2d _frame_size):
    game{_game},
    sprite_sheet{_sprite_sheet},
    frame_size{_frame_size},
    frame_count{0.0f},
    delta_frames{0.2f},
    is_playing{false} {
        
    }

void
Animation::Play(){
    is_playing = true;
}

void
Animation::Stop(){
    is_playing = false;
}

void
Animation::Update(){
    if(is_playing) frame_count += delta_frames;
    UpdateStateLogic();
}

void
Animation::ResetAndPlay(){
    frame_count = 0.0f;
    Play();
}

void
Animation::UpdateStateLogic(){
    /*
    Here goes the instructions for when for example an idle animation should start switching to subanimations. For example:
    if(frame_count > 6000.0f){current_anim = idle_wait;}
    */
}

void
Animation::Draw(Camera* _camera, olc::vf2d _position){

    _camera->DrawRotatedPartialDecal(_position, game->asset_manager.GetDecal(sprite_sheet),{0.0f,0.0f}, GetFrame(int(frame_count)%10).position, frame_size, {1.0f,1.0f});
}

Rect
Animation::GetRectangle(int _x, int _y){
    Rect rect = Rect({(float)(_x * frame_size.x), (float)(_y * frame_size.y)}, frame_size);
    return rect;
}

Rect
Animation::GetFrame(int _frame){
    return GetRectangle(_frame % (int)frame_size.x, (int)_frame/(int)frame_size.y);
}