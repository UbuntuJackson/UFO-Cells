#ifndef GAME_H
#define GAME_H
#include "state.h"
#include <map>
#include <string>

class Game{
public:
    State* game_state;
    std::map <std::string, State*> game_states;
    void SetState(std::string _state, std::string _data);
    virtual void LoadResources();
    Game() = default;
    Game(State* _game_state);
    ~Game();

};

#endif