#include "dummy_test_layer_actor.h"
#include "dummy.h"
#include "optimised_dummy.h"
#include "../../src/ufo/layer_actor.h"
#include "../../src/program/ufo_global.h"
#include <iostream>
#include "../../src/ufo/dynamic_solid.h"
#include "custom_dynamic_solid.h"
#include "../../src/ufo/camera.h"

DummyTestLayerActor::DummyTestLayerActor(DummyTestGame* _game, CellMap* _map ,std::string _name, std::string _type) : LayerActor(_map,_name, _type), game{_game}{}

void
DummyTestLayerActor::LoadLayer(){ //Maybe people can derive from this class and make their own LoadLayer function
    for(auto act : actors_to_create){
        if(act.actor == "Dummy"){
            std::cout << "loaded dummy" << std::endl;

            //it is safe to load decals here, tho we need some kind of game start function
            actors.push_back(new OptimisedDummy(olc::vf2d(act.x, act.y), game)); //temporary solution
        }
        if(act.actor == "DynamicSolid"){
            std::cout << "loaded dummy" << std::endl;

            //it is safe to load decals here, tho we need some kind of game start function
            actors.push_back(new DynamicSolid(olc::vf2d(act.x, act.y),game, "dynamic_solid")); //temporary solution
        }
    }
}

void
DummyTestLayerActor::Draw(Camera* _camera){
    for(auto act : actors){
        act->Draw(_camera);
    }
}