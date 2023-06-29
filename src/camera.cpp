#include "camera.h"
#include <string>
#include "olcPixelGameEngine.h"
#include "program.h"

Camera::Camera(Program *_program) : program{_program}{
    scale = 1.0f;
    vel = {200.0f, 200.0f};
}

void Camera::SetTarget(CellActor *_target){
    target = _target;
}

void
Camera::Follow(){
    position = target->position;
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
Camera::DrawDecal(olc::vf2d _pos, olc::Decal *_decal){

    switch(m_camera_state){
        case ZOOM:
            Zoom();
            break;
        case FOLLOW:
            Follow();
            break;
        case SWITCH:
            Switch();
            break;
        case MOVE:
            Move();
            break;
    }

    olc::vf2d offset_position = _pos - target->position - program->asset_manager.decPin->sprite->Size()/2;
    olc::vf2d scaled_offset_position = offset_position * scale;
    scaled_offset_position += program->GetScreenSize()/2;

    program->DrawDecal(
        scaled_offset_position,
        _decal,
        olc::vf2d(scale, scale));
}