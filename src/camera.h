#ifndef CAMERA_H
#define CAMERA_H
#include <string>
#include "olcPixelGameEngine.h"
#include "cell_actor.h"
class Program;

enum CameraStates{
  FOLLOW, //Camera will be set to seem like it focuses on the center point of a sprite.
  SWITCH, //Transitions from one target to another
    MOVE, //Applies a movement vector to the camera position.
	    //This state would require some parameters I guess
    ZOOM  //Transitions into a different scaling factor. Need to give the program a scaling factor
	    // Transition into
};

class Camera{
public:
    float scale;
    Program *program;
    olc::vf2d position;
    olc::vf2d vel;
    int m_camera_state;
    CellActor* target;
    float target_scale;
    float m_initial_scale_difference;
    float m_delta_scale;
    float m_slow_down_target;

    olc::vf2d m_delta_pos;
    olc::vf2d pos_diff;
    CellActor* new_target;
    olc::vf2d m_decal_wh_offset;

    Camera() = default;
    Camera(Program *_program);
    void SetTarget(CellActor *_target);
    void Zoom();
    void Follow();
    void Move();
    void Switch();
    void SetStateSwitch(CellActor *_target);
    void SetStateZoom(float _target_scale);
    void SetStateMove(olc::vf2d _vel);
    void DrawDecal(olc::vf2d _pos, olc::Decal *_decal);
};
#endif