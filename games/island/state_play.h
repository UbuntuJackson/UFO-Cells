#ifndef STATE_PLAY_H
#define STATE_PLAY_H

#include "../../src/ufo/state.h"

class Island;

class StatePlay : public State{
public:
    Island *game;
    StatePlay() = default;
    StatePlay(Island* _game);
    void Set();
    void Update();
};

#endif