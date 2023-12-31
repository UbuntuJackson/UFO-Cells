#include "layer_actor.h"
#include <string>
#include "../../external/olcPixelGameEngine.h"
#include <iostream>
#include "camera.h"
#include "type_registry.h"
#include "actor_info.h"
#include "level.h"

LayerActor::LayerActor(Level* _level, std::string _name, std::string _type, std::vector<ActorInfo> _actors_to_create) : Layer(_level ,_name, _type),
actors_to_create{_actors_to_create}
{}

LayerActor::~LayerActor(){
    std::cout << "destructor" << std::endl;
    for(auto i : actors){
        delete i;
    }
}

void
LayerActor::AddActorInfo(std::string _actor, int _x, int _y){
    actors_to_create.push_back(ActorInfo{_actor, _x, _y});
}

void
LayerActor::LoadLayer(){ //Will be overwritten by a game for a custom LoadLayer function
    for(auto i : actors_to_create){
        level->NewActor(i.actor, i.x, i.y, name);
    }
}

void
LayerActor::Update(){
    for(auto act : level->actors){
        if(act->layer_tag == name) act->Update();
    }
}

void
LayerActor::Draw(Camera* _camera){
    for(auto act : level->actors){
        if(act->layer_tag == name) act->Draw(_camera);
    }
}