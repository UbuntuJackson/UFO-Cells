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

StateLoad::StateLoad() : State(){

}

void StateLoad::Set(std::string _data){
    UfoGlobal::program.asset_manager.LoadDecal("../games/dummy_test/res/masks/pill_small.png", "decPin");

    asset_index = 0;
    UfoGlobal::program.cell_map.UnloadMap();
    layer_information.clear();

    std::ifstream ifs;
    ifs.open(_data, std::ifstream::in);
    std::string sl = PutFileIntoString(ifs);
    ifs.close();
    cJSON *j = cJSON_Parse(sl.c_str());
    const cJSON *l1 = cJSON_GetObjectItemCaseSensitive(j, "layers");
    for(int i = 0; i < cJSON_GetArraySize(l1); i++){
        const cJSON *item = cJSON_GetArrayItem(l1, i);
        std::string name = cJSON_GetObjectItemCaseSensitive(item, "name") -> valuestring; //All layers have a name
        std::string type = cJSON_GetObjectItemCaseSensitive(item, "type") -> valuestring; //All layers have a type
        if(type == "background"){
            std::string path = cJSON_GetObjectItemCaseSensitive(item, "path") -> valuestring; //Not all have a path, this one applies not to actor layers
            UfoGlobal::program.cell_map.layers.push_back(new LayerBackground(name, type, path));
        }
        if(type == "collision"){
            std::string path = cJSON_GetObjectItemCaseSensitive(item, "path") -> valuestring; //Not all have a path, this one applies not to actor layers
            UfoGlobal::program.cell_map.layers.push_back(new LayerSolid(name, type, path));
        }
        if(type == "terrain"){
            std::string path = cJSON_GetObjectItemCaseSensitive(item, "path") -> valuestring; //Not all have a path, this one applies not to actor layers
            UfoGlobal::program.cell_map.layers.push_back(new LayerTerrain(name, type, path));
        }
        if(type == "actor"){
            std::cout << "actor" << std::endl;
            //std::string path = cJSON_GetObjectItemCaseSensitive(item, "path") -> valuestring; //Not all have a path, this one applies not to actor layers
            const cJSON *actor_layer = cJSON_GetObjectItemCaseSensitive(item, "actors");
            LayerActor* layer_actor = new LayerActor();
            for(int j = 0; j < cJSON_GetArraySize(actor_layer); j++){
                const cJSON *act = cJSON_GetArrayItem(actor_layer, j);
                std::string actor_string = cJSON_GetObjectItemCaseSensitive(act, "actor") -> valuestring;
                int x = cJSON_GetObjectItemCaseSensitive(act, "x") -> valueint;
                int y = cJSON_GetObjectItemCaseSensitive(act, "y") -> valueint;
                layer_actor->AddActorInfo(actor_string, x, y);

            }
            UfoGlobal::program.cell_map.layers.push_back(layer_actor);
        }
    }

    cJSON_Delete(j);
}

void StateLoad::LoadActors(){

}

void StateLoad::Update(){
    if(asset_index < UfoGlobal::program.cell_map.layers.size()){

        UfoGlobal::program.cell_map.layers[asset_index]->LoadLayer();
        asset_index++;
    }
    else{
        //UfoGlobal::program.entities.push_back(new Dummy(olc::vf2d(450.0f, 50.0f)));
        UfoGlobal::program.camera.scale = 3.0f;
        UfoGlobal::program.game->SetState("play", "...");
    }
    UfoGlobal::program.DrawDecal(olc::vf2d(0.0f, 0.0f), UfoGlobal::program.asset_manager.decLoad);
}