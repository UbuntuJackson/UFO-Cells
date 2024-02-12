#ifndef LAYER_INTERFACE
#define LAYER_INTERFACE
class Actor;
class CollisionBody;
class LayerSolid;
class Layer;

template<typename T_Layer>
class LayerInterface{
public:
    T_Layer* layer;
    LayerInterface(T_Layer* _layer) : layer{_layer}{}

    void
    AcceptVisitor(Actor *_actor){
        //_actor->LayerProcess(_layer);
    }
    void
    AcceptVisitor(CollisionBody *_actor){
        _actor->LayerProcess(layer);
    }
};

#endif