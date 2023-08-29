#ifndef GAME_BASE_STATE_H
#define GAME_BASE_STATE_H

#include "../../src/ufo/state.h"
class DummyTestGame;

class GameBaseState : public State{
public:
    DummyTestGame* game;
    GameBaseState(DummyTestGame *game);

};

#endif