#ifndef STATE_PLAY
#define STATE_PLAY

#include "../../src/ufo/state.h"
#include <string>
#include "../../src/ufo/cellmap.h"

class StatePlay : public State{
public:
    std::string current_map; //should be in the main Game class
    CellMap map; //Should have ptr
    StatePlay(Game* _game);
    void Set(std::string _data);
    void Update();

};

#endif