#include "actor.h"
#include "camera.h"
#include <string>

Actor::Actor(int _id, olc::vf2d _position, std::string _layer_tag) : id{_id}, position{_position}, layer_tag{_layer_tag}{}

int
Actor::GetId(){
    return id;
}

void
Actor::Update(){}

void
Actor::Draw(Camera* _camera){}

std::string
Actor::GetType(){
    return "Actor"
}