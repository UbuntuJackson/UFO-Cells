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

void
UfoLoad::Set(std::string _data ,CellMap* _map){
    asset_index = 0;
    _map->UnloadMap();
    layer_information.clear();

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
        std::string name = cJSON_GetObjectItemCaseSensitive(item, "name") -> valuestring;
        std::string type = cJSON_GetObjectItemCaseSensitive(item, "type") -> valuestring;
        if(type == "background"){
            std::string path = cJSON_GetObjectItemCaseSensitive(item, "path") -> valuestring;
            _map->layers.push_back(new LayerBackground(&(game->camera), &(game->map),name, type, path));
        }
        if(type == "collision"){
            std::string path = cJSON_GetObjectItemCaseSensitive(item, "path") -> valuestring;
            _map->layers.push_back(new LayerSolid(&(game->camera), &(game->map),name, type, path));
        }
        if(type == "terrain"){
            std::string path = cJSON_GetObjectItemCaseSensitive(item, "path") -> valuestring;
            _map->layers.push_back(new LayerTerrain(&(game->camera), &(game->map),name, type, path));
        }
        if(type == "actor"){
            const cJSON *actor_layer = cJSON_GetObjectItemCaseSensitive(item, "actors");
            DummyTestLayerActor* layer_actor = new DummyTestLayerActor(game, &(game->camera), &(game->map),name, type);
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

Layer*
UfoLoad::NewLayer(std::string _layer, std::string _name, std::string _type, std::string _path){
    if(_layer == "background"){
        return new LayerBackground(map,_name, _type, _path);
    }
    if(_layer == "collision"){
        
        return new LayerSolid(map,_name, _type, _path);
    }
    if(_layer == "terrain"){
        return new LayerTerrain(map,_name, _type, _path);
    }
}

Layer*
UfoLoad::NewLayer(std::string _layer, std::string _name, std::string _type, ActorInfo _actor_info){
    if(_layer == "actor"){
        return new LayerActor(&(game->camera), &(game->map),_name, _type, _actor_info);
    }
}

