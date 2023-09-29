#include "layer_actor.h"
#include <string>
#include "../../external/olcPixelGameEngine.h"
#include <iostream>
#include "camera.h"
#include "type_registry.h"
#include "actor_info.h"

LayerActor::LayerActor(CellMap* _map, std::string _name, std::string _type, std::vector<ActorInfo> _actors_to_create, TypeRegistry* _type_registry) : Layer(_map ,_name, _type),
actors_to_create{_actors_to_create},
registry{_type_registry}
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
        actors.push_back(registry->NewActor(i.actor,{i.x,i.y}));
    }
}

void
LayerActor::Update(){
    for(auto act : actors){
        act->Update();
    }
}

void
LayerActor::Draw(Camera* _camera){
    for(auto act : actors){
        act->Draw(_camera);
    }
}