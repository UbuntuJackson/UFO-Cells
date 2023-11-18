#ifndef ANIMATION_H
#define ANIMATION_H
#include "rect.h"
#include "../../external/olcPixelGameEngine.h"
#include <string>
#include <vector>
class Game;
class Camera;

class Animation{
public:
    Game* game;
    bool is_playing;

    float delta_frames;
    float frame_count;
    std::string sprite_sheet;
    olc::vf2d frame_size;
    std::vector<int> current_anim; //should not be empty, warn if empty
    std::vector<int> idle_stand; //example, will not remain in this class, but can be added in classes inheriting from this class
    std::vector<int> idle_wait; //example, will not remain in this class, but can be added in classes inheriting from this class
    Animation(Game* _game,olc::vf2d _frame_size, float _delta_frames, std::string _sprite_sheet);
    void Play();
    void Stop();
    void Reset();
    void ResetAndPlay();
    virtual void UpdateStateLogic();
    Rect GetRectangle(int _x, int _y);
    Rect GetFrame(int _frame);
    virtual void Update();
    virtual void Draw(Camera* _camera, olc::vf2d _position, olc::vf2d _scale);
};
#endif