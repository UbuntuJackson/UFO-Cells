#ifndef STATE_LOAD
#define STATE_LOAD

#include "../../src/ufo/state.h"
#include <string>

class StateLoad : public State{
private:
    int asset_index;
public:
    StateLoad();
    void SetLoad(std::string _map);
    void Update();
};

#endif