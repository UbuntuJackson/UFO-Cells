#ifndef STATE_MENU
#define STATE_MENU

#include "../../src/ufo/state.h"
#include <string>

class StateMenu : public State{
public:
    StateMenu();
    void SetMenu(std::string _map);
    void Update();
};

#endif