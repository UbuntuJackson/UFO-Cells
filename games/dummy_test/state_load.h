#ifndef STATE_LOAD
#define STATE_LOAD
#include <vector>
#include "../../src/ufo/state.h"
#include <string>
#include "../../external/cJSON.h"
#include <memory>

class StateLoad : public State{
private:

    struct LayerInfo{
        std::string name;
        std::string type;
        std::string path;
    };

    std::vector<LayerInfo> layer_information;

    int asset_index;
    std::string loading_screen_dir;
public:
    StateLoad();
    void Set(std::string _data);
    void Update();
};

#endif