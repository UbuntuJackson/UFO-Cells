#ifndef GAME_STATE_H
#define GAME_STATE_H
#include "state.h"

class GameState{
    GameState();
    virtual void Request();
    virtual void Update();
    virtual void Draw();
};

#endif