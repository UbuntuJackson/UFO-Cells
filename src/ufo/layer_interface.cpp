#include "layer_interface.h"
#include "collision_body.h"
#include "layer_solid.h"
#include "actor.h"
#include "layer.h"
void
LayerInterface::AcceptVisitor(Actor *_actor, Layer* _layer){
    //_actor->LayerProcess(_layer);
}
void
LayerInterface::AcceptVisitor(CollisionBody *_actor, LayerSolid* _layer){
    _actor->LayerProcess(_layer);
}