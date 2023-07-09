#ifndef GAME_H
#define GAME_H
#include "state.h"
#include <map>
#include <string>

class Game{
public:
    State* game_state;
    std::map <std::string, State*> game_states;
    Game() = default;
    Game(State* _game_state);
    ~Game();

};

#endif