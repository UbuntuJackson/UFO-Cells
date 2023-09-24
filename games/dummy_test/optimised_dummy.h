#ifndef OPTIMISED_DUMMY_H
#define OPTIMISED_DUMMY_H

#include "../../src/ufo/cell_actor.h"
class DummyTestGame;

class OptimisedDummy : public CellActor{
public:
    DummyTestGame* game;
    OptimisedDummy(olc::vf2d _position, DummyTestGame* _game);
    void Update();
    void Draw(Camera* _camera);
};
#endif