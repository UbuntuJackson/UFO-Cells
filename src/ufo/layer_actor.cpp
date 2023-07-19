#include "layer_actor.h"
#include <string>
#include "../../games/dummy_test/dummy.h" //temporary solution
#include "../../external/olcPixelGameEngine.h"
#include <iostream>

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
LayerActor::LoadLayer(){ //Maybe people can derive from this class and make their own LoadLayer function
    for(auto act : actors_to_create){
        if(act.actor == "Dummy"){
            actors.push_back(new Dummy(olc::vf2d(act.x, act.y))); //temporary solution
        }
    }
}

void
LayerActor::Update(){
    for(auto act : actors){
        act->Update();
    }
}

void
LayerActor::Draw(){
    for(auto act : actors){
        act->Draw();
    }
}