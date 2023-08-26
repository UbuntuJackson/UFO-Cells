#ifndef STATE_MENU
#define STATE_MENU

#include "../../src/ufo/state.h"
#include <string>
#include "../../src/ufo/game.h"

class StateMenu : public State{
public:
    std::string menu_string;
    StateMenu(Game* _game);
    std::string GetData();
    void Set(std::string _data);
    void Update();
};

#endif