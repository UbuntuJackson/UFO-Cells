#ifndef CAMERA_H
#define CAMERA_H
#include <string>
#include "../../external/olcPixelGameEngine.h"
#include "cell_actor.h"
#include "mouse_control.h"

enum CameraStates{
    BASIC_FOLLOW,
    RESTRICTED_FOLLOW,
    CLAMPED_FOLLOW,
    FOLLOW_PLATFORMER,
    FOLLOW, //Camera will be set to seem like it focuses on the center point of a sprite.
    SWITCH, //Transitions from one target to another
    MOVE, //Applies a movement vector to the camera position.
	    //This state would require some parameters I guess
    ZOOM,  //Transitions into a different scaling factor. Need to give the program a scaling factor
	    // Transition into
    MOUSE,
    MULTIPLAYER,
    ALL_CONTAINED,
    STATIC,
    PLATFORMER
};

class Camera{
public:
    Game* game;

    float scale;
    olc::vf2d position;
    olc::vf2d centre;
    olc::vf2d vel;
    int m_camera_state;
    CellActor* target;
    float target_scale;
    float m_initial_scale_difference;
    float m_delta_scale;
    float m_slow_down_target;

    olc::vf2d offset;

    float up_sensor;
    float down_sensor;
    float left_sensor;
    float right_sensor;

    olc::vf2d clamp_up_left_corner;
    olc::vf2d clamp_down_right_corner;

    olc::vf2d m_delta_pos;
    olc::vf2d pos_diff;
    CellActor* new_target;
    olc::vf2d m_decal_wh_offset;

    MouseControl mouse_control;

    Camera() = default;
    Camera(Game *_game);
    void SetTarget(CellActor *_target);
    void Zoom();
    void Follow(olc::vf2d _position, olc::Decal *_decal);
    void Follow(olc::vf2d _position, olc::Decal *_decal, olc::vf2d _center, olc::vf2d _source_pos, olc::vf2d _source_size, olc::vf2d _scale);
    void Move();
    void Switch();
    void Static(olc::vf2d _position, olc::Decal *_decal);
    void Static(olc::vf2d _position, olc::Decal *_decal, olc::vf2d _center, olc::vf2d _source_pos, olc::vf2d _source_size, olc::vf2d _scale);
    void MouseAndArrowKeys(olc::vf2d _position, olc::Decal *_decal);
    void MouseAndArrowKeys(olc::vf2d _position, olc::Decal *_decal, olc::vf2d _center, olc::vf2d _source_pos, olc::vf2d _source_size, olc::vf2d _scale);
    void SetStateSwitch(CellActor *_target);
    void SetStateZoom(float _target_scale);
    void SetStateMove(olc::vf2d _vel);
    void SetStateStatic(olc::vf2d _offset);
    void SetStateMouseAndArrowKeys(olc::vf2d top_left_corner, olc::vf2d bottom_right_corner);
    void FollowPlatformer(olc::vf2d _position, olc::Decal *_decal);
    //void FollowPlatformer(olc::vf2d _position, olc::Decal *_decal, olc::vf2d _center, olc::vf2d _source_pos, olc::vf2d _source_size, olc::vf2d _scale);
    
    //This function, Platformer is like the name suggests appropriate for Platforming games.
    //For now it takes the position given and a centre variable into account to define where on the screen the centre of
    //the field of view is. This has not been applied to MouseAndArrowKeys()
    void Platformer(olc::vf2d _position, olc::Decal *_decal);
    void Platformer(olc::vf2d _position, olc::Decal *_decal, olc::vf2d _center, olc::vf2d _source_pos, olc::vf2d _source_size, olc::vf2d _scale);
    void FollowPlatformer(olc::vf2d _position, olc::Decal *_decal, olc::vf2d _center, olc::vf2d _source_pos, olc::vf2d _source_size, olc::vf2d _scale);

    void
    SetStateFollowPlatfomer(CellActor *_target, olc::vf2d top_left_corner, olc::vf2d bottom_right_corner);
    void
    SetStatePlatformer(CellActor *_target, olc::vf2d top_left_corner, olc::vf2d bottom_right_corner);

    olc::vf2d ScreenToWorld(olc::vf2d _screen_position, olc::vf2d _shape_offset);
    olc::vf2d WorldToScreen(olc::vf2d _position, olc::vf2d _shape_offset);

    void DrawDecal(olc::vf2d _position, olc::Decal *_decal);
    void DrawRotatedPartialDecal(olc::vf2d _position, olc::Decal *_decal, olc::vf2d _center, olc::vf2d _source_pos, olc::vf2d _source_size, olc::vf2d _scale);
};
#endif