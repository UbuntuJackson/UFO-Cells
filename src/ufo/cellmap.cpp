#include <filesystem>
#include "cellmap.h"
#include <string>
#include <fstream>
#include <iostream>
#include "../../external/cJSON.h"
#include "file_utils.h"
#include "../../external/olcPixelGameEngine.h"
#include "../program/ufo_global.h"
#include "camera.h"
#include "layer.h"
#include "cell_actor.h"

CellMap::CellMap(Game* _game) : game{_game}, map_path {""}{}

Layer* CellMap::GetLayer(std::string _layer_name){
    for(auto *layer : layers){
        if(layer->name == _layer_name) return layer;
    }
    return nullptr;
}

void
CellMap::NewActor(std::string _actor_type ,int _x, int _y, std::string _layer_tag){
    std::cout << "NewActor base-class" << std::endl;
}

void
CellMap::RemoveActor(int _actor_id){
    for(int i = 0; i < actors.size(); i++){
        if(actors[i]->GetID() == _actor_id){
            std::cout << i << std::endl;
            actors.erase(actors.begin() + i);
        }
    }
}

void
CellMap::DeferActorRemoval(int _actor_id){
    deferred_actor_removals.push_back(_actor_id);
}

void
CellMap::LoadMap(std::string _map_path){ //OUTDATED
    UnloadMap();

    std::ifstream ifs;
    ifs.open(_map_path, std::ifstream::in);
    std::string sl = PutFileIntoString(ifs);
    cJSON *j = cJSON_Parse(sl.c_str());
    const cJSON *l1 = cJSON_GetObjectItemCaseSensitive(j, "layers");
    for(int i = 0; i < cJSON_GetArraySize(l1); i++){
        const cJSON *item = cJSON_GetArrayItem(l1, i);
        std::string name = cJSON_GetObjectItemCaseSensitive(item, "name") -> valuestring;
        std::string type = cJSON_GetObjectItemCaseSensitive(item, "type") -> valuestring;
        std::string path = cJSON_GetObjectItemCaseSensitive(item, "path") -> valuestring;

        if(type == "collision"){

            olc::Sprite *spr = new olc::Sprite(path);
            olc::Decal *dec = new olc::Decal(spr);

            map_size = spr->Size();
            collision_layers[name] = dec;
        }
        if(type == "visible"){

            olc::Sprite *spr = new olc::Sprite(path);
            olc::Decal *dec = new olc::Decal(spr);
            visible_layers.push_back(dec);
        }
    }
}

void CellMap::UnloadMap(){
    for(auto act : actors){
        delete act;
    }
    for(auto &[key, spr] : map_sprites){
        delete spr;
    }
    map_sprites.clear();
     for(auto &[key, dec] : map_decals){
        delete dec;
    }
    std::cout << "unloads map" << std::endl;
    map_decals.clear();
    for(auto layer : layers){
        delete layer;
    }
    layers.clear();
}

CellMap::~CellMap(){UnloadMap();}

void
CellMap::Update(){
    deferred_actor_removals.clear();
    for(auto layer : layers){
        layer->Update();
    }
    for(auto act_id : deferred_actor_removals){
        RemoveActor(act_id);
    }
}

void
CellMap::Draw(Camera* _camera){
    for(auto layer : layers){
        layer->Draw(_camera);
    }
}