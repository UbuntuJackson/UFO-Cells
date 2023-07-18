#ifndef LAYER_ACTOR_H
#define LAYER_ACTOR_H
#include "layer.h"
#include "../../external/olcPixelGameEngine.h"
#include "cell_actor.h"

class LayerActor : public Layer{
public:
    std::vector<CellActor*> actors;
    LayerActor() = default;
    ~LayerActor();
    void Update();
    void Draw();
};

#endif