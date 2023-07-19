#ifndef LAYER_ACTOR_H
#define LAYER_ACTOR_H
#include "layer.h"
#include "../../external/olcPixelGameEngine.h"
#include "cell_actor.h"
#include <vector>

class LayerActor : public Layer{
public:

    struct ActorInfo{
        std::string actor;
        int x;
        int y;
    };
    std::vector<ActorInfo> actors_to_create;

    std::vector<CellActor*> actors; //How about I instantiate it, call AddActorInfo and THEN add it to the vector?
    LayerActor() = default;
    void AddActorInfo(std::string _actor, int _x, int _y);
    ~LayerActor();
    void Update();
    void Draw();
};

#endif