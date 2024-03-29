#include "animation.h"
#include "camera.h"
#include "rect.h"
#include "game.h"
#include "../../external/olcPixelGameEngine.h"
#include <string>
#include "asset_manager.h"

Animation::Animation(Game* _game, olc::vf2d _frame_size, float _delta_frames, std::string _sprite_sheet):
    game{_game},
    frame_size{_frame_size},
    delta_frames{_delta_frames},
    sprite_sheet{_sprite_sheet},
    frame_count{0.0f},
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
Animation::Update(){ //Take state string as argument, for example jump, run, walk... might just be easier to pass in the actor
    if(is_playing){
        frame_count += delta_frames;
    }
    UpdateStateLogic();
}

void
Animation::Reset(){
    frame_count = 0.0f;
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
Animation::Draw(Camera* _camera, olc::vf2d _position, olc::vf2d _scale){
    _camera->DrawRotatedPartialDecal(_position, AssetManager::Get().GetDecal(sprite_sheet),{0.0f,0.0f}, GetFrame(current_anim[(int)frame_count%current_anim.size()]).position, frame_size, _scale);
}

Rect
Animation::GetRectangle(int _x, int _y){
    Rect rect = Rect({(float)(_x * frame_size.x), (float)(_y * frame_size.y)}, frame_size);
    return rect;
}

Rect
Animation::GetFrame(int _frame){
    return GetRectangle(
        (int)_frame % (AssetManager::Get().GetDecal(sprite_sheet)->sprite->Size().x/(int)frame_size.x), //1 can only give me x = 0
        (int)_frame / (AssetManager::Get().GetDecal(sprite_sheet)->sprite->Size().x/(int)frame_size.x)); //1 can only give y = 1
}