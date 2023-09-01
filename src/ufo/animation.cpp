#include "animation.h"
#include "camera.h"

Animation::Animation(){
    current_anim = idle_stand;
    Play();
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
Animation::Draw(Camera* _camera){
    //partial_decal = Decal(w, h);
    //sample bunch of pixles according to a sprite index
    //Draw the created decal with camera
    //Requires lists with chopped up spritesheets to exist

    //Maybe create a function for camera that takes both a decal and an index
}