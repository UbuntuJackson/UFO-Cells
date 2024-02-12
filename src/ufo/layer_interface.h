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
    LayerInterface(T_Layer* _layer) : layer{_layer}{
        Console::Out(layer->type);
    }

    void
    AcceptVisitor(Actor *_actor){
        _actor->LayerProcess(layer);
    }

    void
    AcceptVisitor(CollisionBody *_actor){
        _actor->LayerProcess(layer);
    }
};

#endif