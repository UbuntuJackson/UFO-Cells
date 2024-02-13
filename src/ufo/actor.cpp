#include "actor.h"
#include "camera.h"
#include "../../external/olcPixelGameEngine.h"
#include <string>
#include "layer.h"
#include "layer_interface.h"

Actor::Actor(int _id, olc::vf2d _position, std::string _layer_tag) : id{_id}, position{_position}, layer_tag{_layer_tag}{}

int
Actor::GetID(){
    return id;
}

void
Actor::Update(){}

void
Actor::LayerProcess(Layer* _layer){
    Console::Out("Actor", "LayerProcess");
}

void Actor::GetVisitedByLayerInterface(LayerInterface<Layer>* _interface){
    _interface->AcceptVisitor(this);
    Console::Out(GetType(), "from GetVisitedByLayerInterface");
    Console::Out(_interface->layer->GetType(), "from GetVisitedByLayerInterface");
    LayerProcess(_interface->layer);
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