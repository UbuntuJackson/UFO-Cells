#ifndef STATE_PLAY
#define STATE_PLAY

#include "../../src/ufo/state.h"
#include <string>

class StatePlay : public State{
public:
    std::string current_map;
    StatePlay();
    void SetPlay(std::string _map);
    void Update();
};

#endif