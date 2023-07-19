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


StateLoad::StateLoad() : State(){}

void StateLoad::Set(std::string _data){
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
        std::string path = cJSON_GetObjectItemCaseSensitive(item, "path") -> valuestring; //Not all have a path, this one applies not to actor layers

        layer_information.push_back(LayerInfo{name, type, path}); //What if we created actual layers and give it more specifications in the update function
    }

    cJSON_Delete(j);
}

void StateLoad::LoadActors(){

}

void StateLoad::Update(){
    if(asset_index < layer_information.size()){

        if(layer_information[asset_index].type == "collision"){

            olc::Sprite *spr = new olc::Sprite(layer_information[asset_index].path);
            UfoGlobal::program.cell_map.map_sprites[layer_information[asset_index].name] = spr;

            olc::Decal *dec = new olc::Decal(spr);
            UfoGlobal::program.cell_map.collision_layers[layer_information[asset_index].name] = dec;
            UfoGlobal::program.cell_map.map_size = spr->Size();
        }
        if(layer_information[asset_index].type == "visible"){
            olc::Sprite *spr = new olc::Sprite(layer_information[asset_index].path);
            UfoGlobal::program.cell_map.map_sprites[layer_information[asset_index].name] = spr;

            olc::Decal *dec = new olc::Decal(spr);
            UfoGlobal::program.cell_map.visible_layers.push_back(dec);
            UfoGlobal::program.cell_map.map_size = spr->Size();
            //UfoGlobal::program.DrawDecal(olc::vf2d(0.0f, 0.0f), dec);
        }
        asset_index++;
    }
    else{
        UfoGlobal::program.entities.push_back(new Dummy(olc::vf2d(450.0f, 50.0f)));
        UfoGlobal::program.camera.scale = 3.0f;
        UfoGlobal::program.asset_manager.LoadDecal("../games/dummy_test/res/masks/pill_small.png", "decPin");
        UfoGlobal::program.game->SetState("play", "...");
    }
    UfoGlobal::program.DrawDecal(olc::vf2d(0.0f, 0.0f), UfoGlobal::program.asset_manager.decLoad);
}