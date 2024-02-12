#ifndef LAYER_INTERFACE
#define LAYER_INTERFACE
#include "actor.h"
#include "collision_body.h"
#include "layer.h"
#include "layer_solid.h"
#include "console.h"

template<typename T_Layer>
class LayerInterface{
public:
    T_Layer* layer;
    LayerInterface(T_Layer* _layer) : layer{_layer}{}

    void
    AcceptVisitor(Actor *_actor){
        Console::Out("actor.")
        //_actor->LayerProcess(_layer);
    }
    void
    AcceptVisitor(CollisionBody *_actor){
        _actor->LayerProcess(layer);
    }
};

#endif