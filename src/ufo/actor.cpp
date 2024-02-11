#include "actor.h"
#include "camera.h"
#include "../../external/olcPixelGameEngine.h"
#include <string>
#include "layer.h"

Actor::Actor(int _id, olc::vf2d _position, std::string _layer_tag) : id{_id}, position{_position}, layer_tag{_layer_tag}{}

int
Actor::GetID(){
    return id;
}

void
Actor::Update(){}

void
Actor::LayerProcess(Layer* _layer){
    
}

void
Actor::Draw(Camera* _camera){}

void
Actor::Draw(){}

void
Actor::OnRemoval(){
    remove_pointer_from_container(GetID());
}

std::string
Actor::GetType(){
    return "Actor";
}