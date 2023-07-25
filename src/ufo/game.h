#ifndef GAME_H
#define GAME_H
#include "state.h"
#include <map>
#include <string>
#include "../../external/olcPixelGameEngine.h"

class Game{
public:
    State* game_state;
    const olc::vf2d CHUNK_SIZE = {400, 400};
    std::map <std::string, State*> game_states;
    void SetState(std::string _state, std::string _data);
    virtual void LoadResources();
    Game() = default;
    Game(State* _game_state);
    ~Game();
};

#endif