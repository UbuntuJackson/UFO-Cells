#ifndef GAME_H
#define GAME_H
#include "state.h"

class Game{
public:
    State* game_state;
    Game() = default;
    Game(State* _game_state);
    ~Game();

};

#endif