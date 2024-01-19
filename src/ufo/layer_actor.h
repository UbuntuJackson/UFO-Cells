#ifndef LAYER_ACTOR_H
#define LAYER_ACTOR_H
#include "layer.h"
#include "../../external/olcPixelGameEngine.h"
#include <vector>
#include <string>
#include "actor_info.h"

class CollisionBody;
class Camera;
class Level;

class LayerActor : public Layer{
public:

    std::vector<ActorInfo> actors_to_create;

    std::vector<CollisionBody*> actors; //How about I instantiate it, call AddActorInfo and THEN add it to the vector?
    LayerActor(Level* _level, std::string _name, std::string _type, std::vector<ActorInfo> _actors_to_create);
    ~LayerActor();
    void LoadLayer();
    void AddActorInfo(std::string _actor, int _x, int _y);
    void Update();
    void Draw(Camera* _camera);
};

#endif