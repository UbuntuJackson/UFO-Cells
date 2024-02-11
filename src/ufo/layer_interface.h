#ifndef LAYER_INTERFACE
#define LAYER_INTERFACE
class Actor;
class CollisionBody;
class LayerSolid;
class Layer;

class LayerInterface{
    LayerInterface() = default;
    void AcceptVisitor(Actor *_actor, Layer* _layer);
    void AcceptVisitor(CollisionBody *_actor, LayerSolid* _layer);
};

#endif