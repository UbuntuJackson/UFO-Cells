#include "camera.h"
#include <string>
#include <iostream>
#include "../../external/olcPixelGameEngine.h"
#include "mouse_control.h"
#include "../program/ufo_global.h"
#include "game.h"


Camera::Camera(Game* _game) :
    game{_game},
    mouse_control{MouseControl(game)},
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

    olc::vf2d offset_camera_position = position + game->asset_manager.GetDecal("decPin")->sprite->Size()/2;

    if(offset_camera_position.x < 800.0f/scale) offset_camera_position.x = 800.0f/scale;
    if(offset_camera_position.x > 1600.0f-800.0f/scale) offset_camera_position.x = 1600.0f-800.0f/scale;
    if(offset_camera_position.y < 400.0f/scale) offset_camera_position.y = 400.0f/scale;
    if(offset_camera_position.y > 800.0f-400.0f/scale) offset_camera_position.y = 800.0f-400.0f/scale;


    olc::vf2d offset_position = _position - offset_camera_position;
    olc::vf2d scaled_offset_position = offset_position * scale;
    scaled_offset_position += game->GetScreenSize()/2;

    game->DrawDecal(
        scaled_offset_position,
        _decal,
        olc::vf2d(scale, scale));
}

void
Camera::Follow(olc::vf2d _position, olc::Decal *_decal, olc::vf2d _center, olc::vf2d _source_pos, olc::vf2d _source_size, olc::vf2d _scale){
    position = target->position;

    olc::vf2d offset_camera_position = position + game->asset_manager.GetDecal("decPin")->sprite->Size()/2;

    if(offset_camera_position.x < 800.0f/scale) offset_camera_position.x = 800.0f/scale;
    if(offset_camera_position.x > 1600.0f-800.0f/scale) offset_camera_position.x = 1600.0f-800.0f/scale;
    if(offset_camera_position.y < 400.0f/scale) offset_camera_position.y = 400.0f/scale;
    if(offset_camera_position.y > 800.0f-400.0f/scale) offset_camera_position.y = 800.0f-400.0f/scale;


    olc::vf2d offset_position = _position - offset_camera_position;
    olc::vf2d scaled_offset_position = offset_position * scale;
    scaled_offset_position += game->GetScreenSize()/2;

    game->DrawDecal(
        scaled_offset_position,
        _decal,
        olc::vf2d(scale, scale));
}

void
Camera::SetStateFollowPlatfomer(CellActor *_target, olc::vf2d top_left_corner, olc::vf2d bottom_right_corner){
    clamp_up_left_corner = top_left_corner;
    clamp_down_right_corner = bottom_right_corner;
    m_camera_state = FOLLOW_PLATFORMER;
    target = _target;
    up_sensor = target->position.y - 95.0f;
    down_sensor = target->position.y + 20.0f;
    left_sensor = target->position.x + 75.0f;
    right_sensor = target->position.x - 75.0f;
}

void
Camera::FollowPlatformer(olc::vf2d _position, olc::Decal *_decal){

    position.x = target->position.x;

    if(target->position.y < up_sensor){
        up_sensor = target->position.y;
        down_sensor = up_sensor+90.0f/scale;
    }
    if(target->position.y > down_sensor){
        down_sensor = target->position.y;
        up_sensor = down_sensor-90.0f/scale;
    }

    position.y = up_sensor;

    position.x = std::floor(position.x);
    position.y = std::floor(position.y);

    //Feed this value to WorldToScreen()

    olc::vf2d f_screen_size;
    f_screen_size.x = float(game->GetScreenSize().x);
    f_screen_size.y = float(game->GetScreenSize().y);

    olc::vf2d camera_clamp_min = f_screen_size*0.5f/scale - game->asset_manager.GetDecal("decPin")->sprite->Size()/2;
    olc::vf2d camera_clamp_max = clamp_down_right_corner-f_screen_size*0.5f/scale - game->asset_manager.GetDecal("decPin")->sprite->Size()/2;

    if(position.x < camera_clamp_min.x) position.x = camera_clamp_min.x;
    if(position.y < camera_clamp_min.y) position.y = camera_clamp_min.y;
    if(position.x > camera_clamp_max.x) position.x = camera_clamp_max.x;
    if(position.y > camera_clamp_max.y) position.y = camera_clamp_max.y;

    olc::vf2d offset_camera_position = position + game->asset_manager.GetDecal("decPin")->sprite->Size()/2;

    olc::vf2d offset_position = _position - offset_camera_position;
    olc::vf2d screen_position = offset_position * scale;
    screen_position += f_screen_size*0.5f;

    auto mod = [&](int a, int b){
        if(a%b < 0.0f){
            return a%b + b;
        }
        return a%b;
    };

    screen_position.x = int(std::floor(screen_position.x)) - mod(int(std::floor(screen_position.x)), int(scale)); //This is to maintain coordinates of pixles as multiples of scale.
    screen_position.y = int(std::floor(screen_position.y)) - mod(int(std::floor(screen_position.y)), int(scale)); //This is to maintain coordinates of pixles as multiples of scale.

    game->DrawDecal(
        screen_position,
        _decal,
        olc::vf2d(scale, scale));
}

void
Camera::FollowPlatformer(olc::vf2d _position, olc::Decal *_decal, olc::vf2d _center, olc::vf2d _source_pos, olc::vf2d _source_size, olc::vf2d _scale){

    position.x = target->position.x;

    if(target->position.y < up_sensor){
        up_sensor = target->position.y;
        down_sensor = up_sensor+90.0f/scale;
    }
    if(target->position.y > down_sensor){
        down_sensor = target->position.y;
        up_sensor = down_sensor-90.0f/scale;
    }

    position.y = up_sensor;

    position.x = std::floor(position.x);
    position.y = std::floor(position.y);

    //Feed this value to WorldToScreen()

    olc::vf2d f_screen_size;
    f_screen_size.x = float(game->GetScreenSize().x);
    f_screen_size.y = float(game->GetScreenSize().y);

    olc::vf2d camera_clamp_min = f_screen_size*0.5f/scale - game->asset_manager.GetDecal("decPin")->sprite->Size()/2;
    olc::vf2d camera_clamp_max = clamp_down_right_corner-f_screen_size*0.5f/scale - game->asset_manager.GetDecal("decPin")->sprite->Size()/2;

    if(position.x < camera_clamp_min.x) position.x = camera_clamp_min.x;
    if(position.y < camera_clamp_min.y) position.y = camera_clamp_min.y;
    if(position.x > camera_clamp_max.x) position.x = camera_clamp_max.x;
    if(position.y > camera_clamp_max.y) position.y = camera_clamp_max.y;

    olc::vf2d offset_camera_position = position + game->asset_manager.GetDecal("decPin")->sprite->Size()/2;

    olc::vf2d offset_position = _position - offset_camera_position;
    olc::vf2d screen_position = offset_position * scale;
    screen_position += f_screen_size*0.5f;

    auto mod = [&](int a, int b){
        if(a%b < 0.0f){
            return a%b + b;
        }
        return a%b;
    };

    screen_position.x = int(std::floor(screen_position.x)) - mod(int(std::floor(screen_position.x)), int(scale)); //This is to maintain coordinates of pixles as multiples of scale.
    screen_position.y = int(std::floor(screen_position.y)) - mod(int(std::floor(screen_position.y)), int(scale)); //This is to maintain coordinates of pixles as multiples of scale.

    game->DrawPartialRotatedDecal(
        screen_position,
        _decal,
        0.0f,
        _center,
        _source_pos,
        _source_size,
        olc::vf2d(scale, scale));
}

void
Camera::SetStatePlatformer(CellActor *_target, olc::vf2d top_left_corner, olc::vf2d bottom_right_corner){
    clamp_up_left_corner = top_left_corner;
    clamp_down_right_corner = bottom_right_corner;
    m_camera_state = PLATFORMER;
    target = _target;
    centre = olc::vf2d(game->GetScreenSize().x*0.5f, game->GetScreenSize().y*0.5f)- olc::vf2d(target->mask_decal->sprite->Size().x*0.5f, target->mask_decal->sprite->Size().y*0.5f)*scale;
    up_sensor = target->position.y - 95.0f;
    down_sensor = target->position.y + 20.0f;
    left_sensor = target->position.x + 75.0f;
    right_sensor = target->position.x - 75.0f;
}

void
Camera::Platformer(olc::vf2d _position, olc::Decal *_decal){
    centre = olc::vf2d(game->GetScreenSize().x*0.5f, game->GetScreenSize().y*0.5f)- olc::vf2d(target->mask_decal->sprite->Size().x*0.5f, target->mask_decal->sprite->Size().y*0.5f)*scale;
    std::cout << "platformer" << std::endl;
    position.x = target->position.x;

    if(target->position.y < up_sensor){
        up_sensor = target->position.y;
        down_sensor = up_sensor+90.0f/scale;
    }
    if(target->position.y > down_sensor){
        down_sensor = target->position.y;
        up_sensor = down_sensor-90.0f/scale;
    }

    position.y = up_sensor;

    position.x = std::floor(position.x);
    position.y = std::floor(position.y);

    //Feed this value to WorldToScreen()

    olc::vf2d f_screen_size;
    f_screen_size.x = float(game->GetScreenSize().x);
    f_screen_size.y = float(game->GetScreenSize().y);

    olc::vf2d camera_clamp_min = centre/scale;
    olc::vf2d camera_clamp_max = (clamp_down_right_corner-centre/scale);

    if(position.x < camera_clamp_min.x) position.x = camera_clamp_min.x;
    if(position.y < camera_clamp_min.y) position.y = camera_clamp_min.y;
    if(position.x > camera_clamp_max.x) position.x = camera_clamp_max.x;
    if(position.y > camera_clamp_max.y) position.y = camera_clamp_max.y;

    olc::vf2d screen_position = WorldToScreen(_position, {0.0f,0.0f});

    auto mod = [&](int a, int b){
        if(a%b < 0.0f){
            return a%b + b;
        }
        return a%b;
    };

    screen_position.x = int(std::floor(screen_position.x)) - mod(int(std::floor(screen_position.x)), int(scale)); //This is to maintain coordinates of pixles as multiples of scale.
    screen_position.y = int(std::floor(screen_position.y)) - mod(int(std::floor(screen_position.y)), int(scale)); //This is to maintain coordinates of pixles as multiples of scale.

    game->DrawDecal(
        screen_position,
        _decal,
        olc::vf2d(scale, scale));
}

void
Camera::Platformer(olc::vf2d _position, olc::Decal *_decal, olc::vf2d _center, olc::vf2d _source_pos, olc::vf2d _source_size, olc::vf2d _scale){
    centre = olc::vf2d(game->GetScreenSize().x*0.5f, game->GetScreenSize().y*0.5f)- olc::vf2d(target->mask_decal->sprite->Size().x*0.5f, target->mask_decal->sprite->Size().y*0.5f)*scale;
    position.x = target->position.x;

    if(target->position.y < up_sensor){
        up_sensor = target->position.y;
        down_sensor = up_sensor+90.0f/scale;
    }
    if(target->position.y > down_sensor){
        down_sensor = target->position.y;
        up_sensor = down_sensor-90.0f/scale;
    }

    position.y = up_sensor;

    position.x = std::floor(position.x);
    position.y = std::floor(position.y);

    //Feed this value to WorldToScreen()

    olc::vf2d f_screen_size;
    f_screen_size.x = float(game->GetScreenSize().x);
    f_screen_size.y = float(game->GetScreenSize().y);

    olc::vf2d camera_clamp_min = centre/scale;
    olc::vf2d camera_clamp_max = (clamp_down_right_corner-centre/scale);

    if(position.x < camera_clamp_min.x) position.x = camera_clamp_min.x;
    if(position.y < camera_clamp_min.y) position.y = camera_clamp_min.y;
    if(position.x > camera_clamp_max.x) position.x = camera_clamp_max.x;
    if(position.y > camera_clamp_max.y) position.y = camera_clamp_max.y;

    olc::vf2d screen_position = WorldToScreen(_position, {0.0f,0.0f});

    auto mod = [&](int a, int b){
        if(a%b < 0.0f){
            return a%b + b;
        }
        return a%b;
    };

    screen_position.x = int(std::floor(screen_position.x)) - mod(int(std::floor(screen_position.x)), int(scale)); //This is to maintain coordinates of pixles as multiples of scale.
    screen_position.y = int(std::floor(screen_position.y)) - mod(int(std::floor(screen_position.y)), int(scale)); //This is to maintain coordinates of pixles as multiples of scale.

    game->DrawPartialRotatedDecal(
        screen_position,
        _decal,
        0.0f,
        _center,
        _source_pos,
        _source_size,
        olc::vf2d(scale, scale));
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
Camera::Zoom(){

    if(std::abs(scale - target_scale) < std::abs(m_delta_scale/5.0f)){

        m_delta_scale /= 1.1f;
    }
    scale += m_delta_scale;

}

void
Camera::SetStateSwitch(CellActor *_target){
    m_camera_state = SWITCH;
    new_target = _target;
    pos_diff = new_target -> position - position;
    m_delta_pos = pos_diff / 1.0f;
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
Camera::SetStateMove(olc::vf2d _vel){
    m_camera_state = MOVE;
    vel = _vel;
}

void
Camera::Move(){
    position += vel;
}

void
Camera::SetStateMouseAndArrowKeys(olc::vf2d top_left_corner, olc::vf2d bottom_right_corner){
    clamp_up_left_corner = top_left_corner;
    clamp_down_right_corner = bottom_right_corner;
    m_camera_state = MOUSE;
}

void
Camera::MouseAndArrowKeys(olc::vf2d _position, olc::Decal *_decal){
    olc::vf2d delta_pos = mouse_control.GetDeltaMousePosition();
    //std::cout << UfoGlobal::program.GetMouseWheel() << std::endl;

    if(game->GetMouseWheel() >= 1) scale *= 1.05f;
    if(game->GetMouseWheel() <= -1) scale *= (1.0f/1.05f);

    if(game->GetKey(olc::RIGHT).bHeld) position.x += 2.2f/scale;
    if(game->GetKey(olc::LEFT).bHeld) position.x -= 2.2f/scale;
    if(game->GetKey(olc::UP).bHeld) position.y -= 2.2f/scale;
    if(game->GetKey(olc::DOWN).bHeld) position.y += 2.2f/scale;

    if(game->GetMouse(2).bHeld || game->GetMouse(0).bHeld) position -= delta_pos/scale;

    //Feed this value to world to screen

    olc::vf2d f_screen_size;
    f_screen_size.x = float(game->GetScreenSize().x);
    f_screen_size.y = float(game->GetScreenSize().y);

    //We wanna clamp the position, not the offset_camera_position
    olc::vf2d camera_clamp_min = f_screen_size*0.5f/scale;
    //std::cout << camera_clamp_min.x << ", " << camera_clamp_min.y << std::endl;
    olc::vf2d camera_clamp_max = clamp_down_right_corner-f_screen_size*0.5f/scale;
    //std::cout << camera_clamp_max.x << ", " << camera_clamp_max.y << std::endl;

    if(position.x < camera_clamp_min.x) position.x = camera_clamp_min.x;
    if(position.y < camera_clamp_min.y) position.y = camera_clamp_min.y;
    if(position.x > camera_clamp_max.x) position.x = camera_clamp_max.x;
    if(position.y > camera_clamp_max.y) position.y = camera_clamp_max.y;

    olc::vf2d offset_camera_position = position;

    olc::vf2d offset_position = _position - offset_camera_position;
    olc::vf2d screen_position = offset_position * scale;
    screen_position += f_screen_size*0.5f;

    game->DrawDecal(
        screen_position,
        _decal,
        olc::vf2d(scale, scale));

}

void
Camera::MouseAndArrowKeys(olc::vf2d _position, olc::Decal *_decal, olc::vf2d _center, olc::vf2d _source_pos, olc::vf2d _source_size, olc::vf2d _scale){
    olc::vf2d delta_pos = mouse_control.GetDeltaMousePosition();
    //std::cout << UfoGlobal::program.GetMouseWheel() << std::endl;

    if(game->GetMouseWheel() >= 1) scale *= 1.05f;
    if(game->GetMouseWheel() <= -1) scale *= (1.0f/1.05f);

    if(game->GetKey(olc::RIGHT).bHeld) position.x += 2.2f/scale;
    if(game->GetKey(olc::LEFT).bHeld) position.x -= 2.2f/scale;
    if(game->GetKey(olc::UP).bHeld) position.y -= 2.2f/scale;
    if(game->GetKey(olc::DOWN).bHeld) position.y += 2.2f/scale;

    if(game->GetMouse(2).bHeld || game->GetMouse(0).bHeld) position -= delta_pos/scale;

    //Feed this value to world to screen

    olc::vf2d f_screen_size;
    f_screen_size.x = float(game->GetScreenSize().x);
    f_screen_size.y = float(game->GetScreenSize().y);

    //We wanna clamp the position, not the offset_camera_position
    olc::vf2d camera_clamp_min = f_screen_size*0.5f/scale;
    //std::cout << camera_clamp_min.x << ", " << camera_clamp_min.y << std::endl;
    olc::vf2d camera_clamp_max = clamp_down_right_corner-f_screen_size*0.5f/scale;
    //std::cout << camera_clamp_max.x << ", " << camera_clamp_max.y << std::endl;

    if(position.x < camera_clamp_min.x) position.x = camera_clamp_min.x;
    if(position.y < camera_clamp_min.y) position.y = camera_clamp_min.y;
    if(position.x > camera_clamp_max.x) position.x = camera_clamp_max.x;
    if(position.y > camera_clamp_max.y) position.y = camera_clamp_max.y;

    olc::vf2d offset_camera_position = position;

    olc::vf2d offset_position = _position - offset_camera_position;
    olc::vf2d screen_position = offset_position * scale;
    screen_position += f_screen_size*0.5f;

    game->DrawPartialRotatedDecal(
        screen_position,
        _decal,
        0.0f,
        _center,
        _source_pos,
        _source_size,
        olc::vf2d(scale * _scale.x, scale * _scale.y));

}

void Camera::Static(olc::vf2d _position, olc::Decal *_decal){
    olc::vf2d screen_position;
    screen_position.x = floor((_position.x - offset.x) * scale);
    screen_position.y = floor((_position.y - offset.y) * scale);

    game->DrawDecal(
        screen_position,
        _decal, olc::vd2d(scale, scale));
}

void Camera::Static(olc::vf2d _position, olc::Decal *_decal, olc::vf2d _center, olc::vf2d _source_pos, olc::vf2d _source_size, olc::vf2d _scale){
    olc::vf2d screen_position;
    screen_position.x = floor((_position.x - offset.x) * scale);
    screen_position.y = floor((_position.y - offset.y) * scale);

    game->DrawDecal(
        screen_position,
        _decal, olc::vd2d(scale, scale));
}

void
Camera::SetStateStatic(olc::vf2d _offset){
    offset = _offset;
    m_camera_state = STATIC;
}

olc::vf2d Camera::ScreenToWorld(olc::vf2d _screen_position, olc::vf2d _shape_offset){

    _screen_position -= olc::vf2d(float(centre.x), float(centre.y));
    olc::vf2d offset_position = _screen_position/scale;
    olc::vf2d offset_camera_position = position;
    olc::vf2d world_position = offset_position + offset_camera_position;

    return world_position;
}
olc::vf2d Camera::WorldToScreen(olc::vf2d _position, olc::vf2d _shape_offset){
    olc::vf2d offset_position = _position - position;
    olc::vf2d screen_position = scale * offset_position;

    screen_position += olc::vf2d(float(centre.x), float(centre.y));
    return screen_position;
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
        case STATIC:
            Static(_position, _decal);
            break;
        case PLATFORMER:
            Platformer(_position, _decal);
            break;
    }
}

void
Camera::DrawRotatedPartialDecal(olc::vf2d _position, olc::Decal *_decal, olc::vf2d _center, olc::vf2d _source_pos, olc::vf2d _source_size, olc::vf2d _scale){
    switch(m_camera_state){
        case ZOOM:
            Zoom();
            break;
        case FOLLOW:
            Follow(_position, _decal, _center,_source_pos,_source_size, _scale);
            break;
        case SWITCH:
            Switch();
            break;
        case MOVE:
            Move();
            break;
        case MOUSE:
            MouseAndArrowKeys(_position, _decal, _center,_source_pos,_source_size, _scale);
            break;
        case MULTIPLAYER:
            break;
        case FOLLOW_PLATFORMER:
            FollowPlatformer(_position, _decal, _center,_source_pos,_source_size, _scale);
            break;
        case STATIC:
            Static(_position, _decal, _center,_source_pos,_source_size, _scale);
            break;
        case PLATFORMER:
            Platformer(_position, _decal, _center,_source_pos,_source_size, _scale);
            break;
    }
}