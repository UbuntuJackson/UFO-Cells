#ifndef STATE_LOAD
#define STATE_LOAD
#include <vector>
#include "../../src/ufo/state.h"
#include <string>
#include "../../external/cJSON.h"
#include <memory>
#include "game_base_state.h"

class StateLoad : public GameBaseState{
private:

    struct LayerInfo{
        std::string name;
        std::string type;
        std::string path;
    };

    std::vector<LayerInfo> layer_information;

    int asset_index;
    //std::string current_data = "";
    //std::string former_data = "";
    //bool layers_are_added = false;
    std::string loading_screen_dir;
public:
    StateLoad(DummyTestGame* _game);
    void Set(std::string _data);
    void Update();
};

#endif