#ifndef STATE_MENU
#define STATE_MENU

#include "../../src/ufo/state.h"
#include <string>
#include "../../src/ufo/game.h"
#include "game_base_state.h"

class StateMenu : public GameBaseState{
public:
    std::string menu_string;
    StateMenu(DummyTestGame* _game);
    std::string GetData();
    void Set(std::string _data);
    void Update();
};

#endif