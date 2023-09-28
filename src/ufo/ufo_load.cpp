#include "ufo_load.h"
#include <fstream>
#include <iostream>
#include "../../external/cJSON.h"
#include "../../src/ufo/file_utils.h"
#include "game.h"
#include "cellmap.h"
#include "layer.h"
#include "layer_actor.h"
#include "layer_background.h"
#include "layer_solid.h"
#include "layer_terrain.h"

UfoLoad::UfoLoad(Game *_game, TypeRegistry *_registry) : game{_game}, registry{_registry}{
    
}

void
UfoLoad::Set(std::string _data ,CellMap* _map){
    asset_index = 0;
    _map->UnloadMap();

    std::ifstream ifs;
    ifs.open(_data, std::ifstream::in);
    std::string sl = PutFileIntoString(ifs);
    ifs.close();
    cJSON *j = cJSON_Parse(sl.c_str());
    const cJSON *l1 = cJSON_GetObjectItemCaseSensitive(j, "layers"); //Make GetLayers function
    for(int i = 0; i < cJSON_GetArraySize(l1); i++){
        const cJSON *item = cJSON_GetArrayItem(l1, i); //Would need to pass item, could parse item from here. The function would be called
                                                        //void StateLoad::AddLayers(const cJson _item); Alternatively we could get the whole
                                                        //Json object cJson *j and iterate through it
        std::string category = cJSON_GetObjectItemCaseSensitive(item, "category") -> valuestring;
        std::string name = cJSON_GetObjectItemCaseSensitive(item, "name") -> valuestring;
        std::string type = cJSON_GetObjectItemCaseSensitive(item, "type") -> valuestring;
        if(category == "other"){
            std::string path = cJSON_GetObjectItemCaseSensitive(item, "path") -> valuestring;
            map->layers.push_back(NewLayer(type,name,path));
        }
        if(category == "actor"){
            const cJSON *actor_layer = cJSON_GetObjectItemCaseSensitive(item, "actors");
            std::vector<ActorInfo> layer_information;
            for(int j = 0; j < cJSON_GetArraySize(actor_layer); j++){
                const cJSON *act = cJSON_GetArrayItem(actor_layer, j);
                std::string actor_string = cJSON_GetObjectItemCaseSensitive(act, "actor") -> valuestring;
                int x = cJSON_GetObjectItemCaseSensitive(act, "x") -> valueint;
                int y = cJSON_GetObjectItemCaseSensitive(act, "y") -> valueint;
                layer_information.push_back(ActorInfo{actor_string, x, y});

            }
            map->layers.push_back(NewLayer(name,type,layer_information));
            
        }
    }

    cJSON_Delete(j);
}

void UfoLoad::Update(){ //this can be generalised and put in some kind of class that we derive from
    if(asset_index < map->layers.size()){
        map->layers[asset_index]->LoadLayer();
        asset_index++;
    }
    else{
        //we can just add another state and then set that state, as they are mapped with strings
        game->SetState("play", "...");
    }
    game->DrawDecal(olc::vf2d(0.0f, 0.0f), game->asset_manager.GetDecal("load"));
}

Layer*
UfoLoad::NewLayer(std::string _name, std::string _type, std::string _path){
    if(_type == "background"){
        return new LayerBackground(map,_name, _type, _path);
    }
    if(_type == "collision"){
        
        return new LayerSolid(map,_name, _type, _path);
    }
    if(_type == "terrain"){
        return new LayerTerrain(map,_name, _type, _path);
    }
}

Layer*
UfoLoad::NewLayer(std::string _name, std::string _type, std::vector<ActorInfo> _layer_info){
    if(_type == "actor"){
        return new LayerActor(map ,_name, _type, _layer_info, registry);
    }
}

