
#ifndef STATE_DEFAULT_H
#define STATE_DEFAULT_H

#include "../../src/ufo/state.h"
#include "../../external/olcPixelGameEngine.h"
class Leg0;

class StateDefault : public State{
public:
    int count = 0;
    bool flip = false;
    StateDefault(Game* _game);
    void Update();
};
#endif