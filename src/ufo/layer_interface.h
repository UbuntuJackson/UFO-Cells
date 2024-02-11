#ifndef LAYER_INTERFACE
#define LAYER_INTERFACE
class Actor;
class CollisionBody;
class LayerSolid;
class Layer;

class LayerInterface{
public:
    LayerInterface() = default;
    virtual void AcceptVisitor(Actor *_actor, Layer* _layer);
    virtual void AcceptVisitor(CollisionBody *_actor, LayerSolid* _layer);
};

#endif