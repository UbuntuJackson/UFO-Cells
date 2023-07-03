#include "camera.h"
#include <string>
#include "../../external/olcPixelGameEngine.h"
#include "../program/program.h"
#include "mouse_control.h"
#include "../program/ufo_global.h"

Camera::Camera() :
    mouse_control{MouseControl()},
    scale{1.0f},
    vel{olc::vf2d(200.0f, 200.0f)}
{
}

void Camera::SetTarget(CellActor *_target){
    target = _target;
}

void
Camera::Follow(olc::vf2d _position, olc::Decal *_decal){
    position = target->position;

    std::cout << position.x << std::endl;

    olc::vf2d offset_camera_position = position + UfoGlobal::program.asset_manager.decPin->sprite->Size()/2;

    if(offset_camera_position.x < 800.0f/scale) offset_camera_position.x = 800.0f/scale;
    if(offset_camera_position.x > 1600.0f-800.0f/scale) offset_camera_position.x = 1600.0f-800.0f/scale;
    if(offset_camera_position.y < 400.0f/scale) offset_camera_position.y = 400.0f/scale;
    if(offset_camera_position.y > 800.0f-400.0f/scale) offset_camera_position.y = 800.0f-400.0f/scale;


    olc::vf2d offset_position = _position - offset_camera_position;
    olc::vf2d scaled_offset_position = offset_position * scale;
    scaled_offset_position += UfoGlobal::program.GetScreenSize()/2;

    UfoGlobal::program.DrawDecal(
        scaled_offset_position,
        _decal,
        olc::vf2d(scale, scale));
}

void
Camera::FollowPlatformer(olc::vf2d _position, olc::Decal *_decal){

    position.x = target->position.x;

    if(target->position.y < up_sensor){
        up_sensor = target->position.y-1.0f;
        down_sensor = up_sensor+135.0f;
    }
    if(target->position.y > down_sensor){
        down_sensor = target->position.y+1.0f;
        up_sensor = down_sensor-135.0f;
    }

    position.y = up_sensor+80.0f;

    olc::vf2d offset_camera_position = position + UfoGlobal::program.asset_manager.decPin->sprite->Size()/2;

    if(offset_camera_position.x < 800.0f/scale) offset_camera_position.x = 800.0f/scale;
    if(offset_camera_position.x > 2200.0f-800.0f/scale) offset_camera_position.x = 2200.0f-800.0f/scale;
    if(offset_camera_position.y < 400.0f/scale) offset_camera_position.y = 400.0f/scale;
    if(offset_camera_position.y > 800.0f-400.0f/scale) offset_camera_position.y = 800.0f-400.0f/scale;

    olc::vf2d offset_position = _position - offset_camera_position;
    olc::vf2d scaled_offset_position = offset_position * scale;
    scaled_offset_position += UfoGlobal::program.GetScreenSize()/2;

    UfoGlobal::program.DrawDecal(
        scaled_offset_position,
        _decal,
        olc::vf2d(scale, scale));
}

void
Camera::Zoom(){

    if(std::abs(scale - target_scale) < std::abs(m_delta_scale/5.0f)){

        m_delta_scale /= 1.1f;
    }
    scale += m_delta_scale;

}
void
Camera::SetStateZoom(float _target_scale){
    m_camera_state = ZOOM;
    target_scale = _target_scale;
    position = {0.0, 0.0};
    m_initial_scale_difference = target_scale - scale;

    m_delta_scale = (target_scale - scale) / 2.0f;
    m_slow_down_target = m_initial_scale_difference * 0.2f;
}

void
Camera::Switch(){

    if(std::sqrt(std::abs((new_target -> position - position).x)*std::abs((new_target -> position - position).x) +
        std::abs((new_target -> position - position).y)*std::abs((new_target -> position - position).y))
        < std::sqrt(std::abs((m_delta_pos).x)*std::abs((m_delta_pos).x) +
        std::abs((m_delta_pos).y)*std::abs((m_delta_pos).y)) / 2.5f
    ){
        m_delta_pos /= 1.5f;
    }
    if(std::sqrt(std::abs((new_target -> position - position).x)*std::abs((new_target -> position - position).x) +
        std::abs((new_target -> position - position).y)*std::abs((new_target -> position - position).y)) <
        0.2f
    ){
        target = new_target;
        m_camera_state = FOLLOW;
    }
    position += (m_delta_pos);
}

void
Camera::SetStateSwitch(CellActor *_target){
    m_camera_state = SWITCH;
    new_target = _target;
    pos_diff = new_target -> position - position;
    m_delta_pos = pos_diff / 1.0f;
}

void
Camera::SetStateMove(olc::vf2d _vel){
    m_camera_state = MOVE;
    vel = _vel;
}

void
Camera::Move(){
    position += vel;
}

void
Camera::MouseAndArrowKeys(olc::vf2d _position, olc::Decal *_decal){
    olc::vf2d delta_pos = mouse_control.GetDeltaMousePosition();
    std::cout << UfoGlobal::program.GetMouseWheel() << std::endl;

    //if(program->GetMouseWheel()/240 >= 1) scale *= 2.0f;
    //if(program->GetMouseWheel()/240 <= -1) scale *= 0.5f;

    if(UfoGlobal::program.GetKey(olc::RIGHT).bHeld) position.x += 2.2f/scale;
    if(UfoGlobal::program.GetKey(olc::LEFT).bHeld) position.x -= 2.2f/scale;
    if(UfoGlobal::program.GetKey(olc::UP).bHeld) position.y -= 2.2f/scale;
    if(UfoGlobal::program.GetKey(olc::DOWN).bHeld) position.y += 2.2f/scale;

    if(UfoGlobal::program.GetMouse(0).bHeld) position -= delta_pos/scale;
    if(position.x < 0.0f) position.x = 0.0f;
    if(position.x > 1600 - 1600 / scale) position.x = 1600 - 1600 / scale;
    if(position.y < 0.0f) position.y = 0.0f;
    if(position.y > 800 - 800 / scale) position.y = 800 - 800 / scale;

    olc::vf2d draw_pos = scale*(_position - position);

    UfoGlobal::program.DrawDecal(
        draw_pos,
        _decal,
        olc::vf2d(scale, scale));

}

void
Camera::SetStateFollowPlatfomer(CellActor *_target){
    UfoGlobal::program.camera.m_camera_state = FOLLOW_PLATFORMER;
    target = _target;
    up_sensor = target->position.y - 125.0f;
    down_sensor = target->position.y + 10.0f;
    left_sensor = target->position.x + 75.0f;
    right_sensor = target->position.x - 75.0f;
}

olc::vf2d Camera::ScreenToWorld(olc::vf2d _position){
    _position -= UfoGlobal::program.GetScreenSize()/2;
    olc::vf2d unscaled_offset_position = _position / scale;
    olc::vf2d world_position = unscaled_offset_position + position;
    return world_position;
}
olc::vf2d Camera::WorldToScreen(olc::vf2d _position){
    olc::vf2d offset_position = _position - position;
    olc::vf2d scaled_offset_position = offset_position * scale;
    scaled_offset_position += UfoGlobal::program.GetScreenSize()/2;
    return scaled_offset_position;
}

void
Camera::DrawDecal(olc::vf2d _position, olc::Decal *_decal){

    switch(m_camera_state){
        case ZOOM:
            Zoom();
            break;
        case FOLLOW:
            Follow(_position, _decal);
            break;
        case SWITCH:
            Switch();
            break;
        case MOVE:
            Move();
            break;
        case MOUSE:
            MouseAndArrowKeys(_position, _decal);
            break;
        case MULTIPLAYER:
            break;
        case FOLLOW_PLATFORMER:
            FollowPlatformer(_position, _decal);
            break;
    }

    /*olc::vf2d offset_position = _position - target->position - program->asset_manager.decPin->sprite->Size()/2;
    olc::vf2d scaled_offset_position = offset_position * scale;
    scaled_offset_position += program->GetScreenSize()/2;

    program->DrawDecal(
        scaled_offset_position,
        _decal,
        olc::vf2d(scale, scale));*/
}