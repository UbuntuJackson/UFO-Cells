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
#include "../../external/olcPixelGameEngine.h"

StateLoad::StateLoad() : State(){}

void StateLoad::SetLoad(std::string _map){

    UfoGlobal::program.cell_map.UnloadMap();
    std::ifstream ifs;
    ifs.open(_map, std::ifstream::in);
    std::string sl = PutFileIntoString(ifs);
    cJSON *j = cJSON_Parse(sl.c_str());
    l1 = cJSON_GetObjectItemCaseSensitive(j, "layers");
}

void StateLoad::Update(){

    if(asset_index < cJSON_GetArraySize(l1)){
        const cJSON *item = cJSON_GetArrayItem(l1, asset_index);
        std::string name = cJSON_GetObjectItemCaseSensitive(item, "name") -> valuestring;
        std::string type = cJSON_GetObjectItemCaseSensitive(item, "type") -> valuestring;
        std::string path = cJSON_GetObjectItemCaseSensitive(item, "path") -> valuestring;

        if(type == "collision"){

            olc::Sprite *spr = new olc::Sprite(path);
            olc::Decal *dec = new olc::Decal(spr);
            UfoGlobal::program.cell_map.collision_layers[name] = dec;
            UfoGlobal::program.cell_map.map_size = spr->Size();
        }
        if(type == "visible"){

            olc::Sprite *spr = new olc::Sprite(path);
            olc::Decal *dec = new olc::Decal(spr);
            UfoGlobal::program.cell_map.visible_layers.push_back(dec);
            std::cout << path << std::endl;
            UfoGlobal::program.cell_map.map_size = spr->Size();
            //UfoGlobal::program.DrawDecal(olc::vf2d(0.0f, 0.0f), dec);
        }
        asset_index++;
    }
    else{
        UfoGlobal::program.game->game_state = UfoGlobal::program.game->game_states["play"];
    }
    UfoGlobal::program.DrawDecal(olc::vf2d(0.0f, 0.0f), UfoGlobal::program.asset_manager.decLoad);
}