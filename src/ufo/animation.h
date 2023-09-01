#ifndef ANIMATION_H
#define ANIMATION_H

#include "../../external/olcPixelGameEngine.h"
#include <string>
#include <vector>
class Animation{
public:
    float delta_frames;
    float frame_count;
    bool is_playing;
    std::string sprite_sheet;
    std::vector<int> current_anim;
    std::vector<int> idle_stand; //example, will not remain in this class, but can be added in classes inheriting from this class
    std::vector<int> idle_wait; //example, will not remain in this class, but can be added in classes inheriting from this class
    Animation() = default;
    Animation(std::string _sprite_sheet);
    void Play();
    void Stop();
    void ResetAndPlay();
    void UpdateStateLogic();
    void Update();
    void Draw(Camera* _camera);
};
#endif