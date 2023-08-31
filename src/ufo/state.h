#ifndef STATE_H
#define STATE_H
#include <string>
#include "state.h"

class Game;

class State{
public:
    Game* game;
    State() = default;
    State(Game *_game);
    ~State();
    virtual void SetPlay(std::string _map);
    virtual void SetLoad(std::string _map);
    virtual void SetMenu(std::string _menu);
    virtual void Update();
    virtual void Set(std::string _data);
    virtual std::string GetData();
};

#endif