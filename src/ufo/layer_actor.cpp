#include "layer_actor.h"
#include <string>
#include "../../external/olcPixelGameEngine.h"
#include <iostream>
#include "camera.h"

LayerActor::LayerActor(Camera* _camera, CellMap* _map, std::string _name, std::string _type) : Layer(_camera, _map ,_name, _type){}

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
    std::cout << "load layer on parent was called" << std::endl;
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