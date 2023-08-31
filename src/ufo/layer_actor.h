#ifndef LAYER_ACTOR_H
#define LAYER_ACTOR_H
#include "layer.h"
#include "../../external/olcPixelGameEngine.h"
#include <vector>
#include <string>

class CellActor;
class Camera;

class LayerActor : public Layer{
public:

    struct ActorInfo{
        std::string actor;
        int x;
        int y;
    };
    std::vector<ActorInfo> actors_to_create;

    std::vector<CellActor*> actors; //How about I instantiate it, call AddActorInfo and THEN add it to the vector?
    LayerActor(Camera* _camera,CellMap* _map, std::string _name, std::string _type);
    ~LayerActor();
    void LoadLayer();
    void AddActorInfo(std::string _actor, int _x, int _y);
    void Update();
    void Draw(Camera* _camera);
};

#endif