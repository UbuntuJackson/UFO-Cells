#include "dummy_test_layer_actor.h"
#include "dummy.h"
#include "../../src/ufo/layer_actor.h"
#include "../../src/program/ufo_global.h"
#include <iostream>

DummyTestLayerActor::DummyTestLayerActor() : LayerActor(){}

void
DummyTestLayerActor::LoadLayer(){ //Maybe people can derive from this class and make their own LoadLayer function
    for(auto act : actors_to_create){
        if(act.actor == "Dummy"){
            std::cout << "loaded dummy" << std::endl;

            //it is safe to load decals here, tho we need some kind of game start function
            actors.push_back(new Dummy(olc::vf2d(act.x, act.y))); //temporary solution
        }
    }
}