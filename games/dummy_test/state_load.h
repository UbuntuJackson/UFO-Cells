#ifndef STATE_LOAD
#define STATE_LOAD

#include "../../src/ufo/state.h"
#include <string>
#include "../../external/cJSON.h"

class StateLoad : public State{
private:
    int asset_index;
    const cJSON *l1;
    std::string loading_screen_dir;
public:
    StateLoad();
    void SetLoad(std::string _map);
    void Update();
};

#endif