#include "layer.h"
#include "game.h"
#include "level.h"
#include "actor.h"
#include "layer_interface.h"

Layer::Layer(Level* _level, std::string _name, std::string _type) : level{_level}, name{_name}, type{_type}{}

Layer::~Layer(){}

void Layer::LoadLayer(){} //Map has a pointer to game tho

void Layer::ProcessActors(){
    for(auto actor : level->actors) AcceptVisitor(actor);
}

void Layer::AcceptVisitor(Actor* _actor){
    LayerInterface interface{this};
    _actor->GetVisitedByLayerInterface(&interface);
}
void Layer::Update(){}
void Layer::Draw(Camera* _camera){}