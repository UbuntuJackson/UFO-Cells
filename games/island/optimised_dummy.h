#ifndef OPTIMISED_DUMMY_H
#define OPTIMISED_DUMMY_H

#include "../../src/ufo/cell_actor.h"
#include "../../src/ufo/player_ray.h"
class Island;

class OptimisedDummy : public CellActor{
public:
    PlayerRay ray;
    Island* game;
    OptimisedDummy(olc::vf2d _position, Island* _game);
    void Update();
    void Draw(Camera* _camera);
};
#endif