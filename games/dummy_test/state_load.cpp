#include "state_load.h"
#include <iostream>
#include "../../src/program/ufo_global.h"
#include <string>
#include <fstream>
#include <iostream>
#include "../../external/cJSON.h"
#include "../../src/ufo/file_utils.h"
#include "../../src/ufo/game.h"
#include "dummy_test_game.h"
#include "dummy.h"
#include "../../external/olcPixelGameEngine.h"
#include "../../src/ufo/layer.h"
#include "../../src/ufo/layer_background.h"
#include "../../src/ufo/layer_solid.h"
#include "../../src/ufo/layer_actor.h"
#include "../../src/ufo/layer_terrain.h"
#include "state_load.h"
#include "dummy_test_layer_actor.h"
#include "game_base_state.h"

StateLoad::StateLoad(DummyTestGame* _game) : GameBaseState(_game){

}

void StateLoad::Set(std::string _data){ //this needs to be simplified somehow
    
    asset_index = 0;
    game->map.UnloadMap();
    layer_information.clear();

    std::ifstream ifs;
    ifs.open(_data, std::ifstream::in);
    std::string sl = PutFileIntoString(ifs);
    ifs.close();
    cJSON *j = cJSON_Parse(sl.c_str());
    const cJSON *l1 = cJSON_GetObjectItemCaseSensitive(j, "layers");
    for(int i = 0; i < cJSON_GetArraySize(l1); i++){
        const cJSON *item = cJSON_GetArrayItem(l1, i); //Would need to pass item, could parse item from here. The function would be called
                                                        //void StateLoad::AddLayers(const cJson _item); Alternatively we could get the whole
                                                        //Json object cJson *j and iterate through it
        std::string name = cJSON_GetObjectItemCaseSensitive(item, "name") -> valuestring;
        std::string type = cJSON_GetObjectItemCaseSensitive(item, "type") -> valuestring;
        if(type == "background"){
            std::string path = cJSON_GetObjectItemCaseSensitive(item, "path") -> valuestring;
            game->map.layers.push_back(new LayerBackground(name, type, path));
        }
        if(type == "collision"){
            std::string path = cJSON_GetObjectItemCaseSensitive(item, "path") -> valuestring;
            game->map.layers.push_back(new LayerSolid(name, type, path));
        }
        if(type == "terrain"){
            std::string path = cJSON_GetObjectItemCaseSensitive(item, "path") -> valuestring;
            game->map.layers.push_back(new LayerTerrain(name, type, path));
        }
        if(type == "actor"){
            const cJSON *actor_layer = cJSON_GetObjectItemCaseSensitive(item, "actors");
            DummyTestLayerActor* layer_actor = new DummyTestLayerActor(name, type);
            for(int j = 0; j < cJSON_GetArraySize(actor_layer); j++){
                const cJSON *act = cJSON_GetArrayItem(actor_layer, j);
                std::string actor_string = cJSON_GetObjectItemCaseSensitive(act, "actor") -> valuestring;
                int x = cJSON_GetObjectItemCaseSensitive(act, "x") -> valueint;
                int y = cJSON_GetObjectItemCaseSensitive(act, "y") -> valueint;
                layer_actor->AddActorInfo(actor_string, x, y);

            }
            game->map.layers.push_back(layer_actor);
        }
    }

    cJSON_Delete(j);
}

void StateLoad::Update(){ //this can be generalised and put in some kind of class that we derive from
    if(asset_index < game->map.layers.size()){
        game->map.layers[asset_index]->LoadLayer();
        asset_index++;
    }
    else{
        //we can just add another state and then set that state, as they are mapped with strings
        game->SetState("play", "...");
    }
    game->DrawDecal(olc::vf2d(0.0f, 0.0f), game->asset_manager.GetDecal("load"));
}