#include <filesystem>
#include "cellmap.h"
#include <string>
#include <fstream>
#include <iostream>
#include "../../external/cJSON.h"
#include "file_utils.h"
#include "../../external/olcPixelGameEngine.h"
#include "../program/ufo_global.h"

CellMap::CellMap() : map_path {""}{}

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
CellMap::Draw(){
    /*for(int d = 0; d < visible_layers.size(); d++){

        for(auto &e : UfoGlobal::program.entities){
            if(e->draw_layer == d) e->Draw();
        }

        UfoGlobal::program.camera.DrawDecal(
            olc::vf2d(0.0f, 0.0f),
            visible_layers[d]);
    }*/
    for(auto layer : layers){
        layer->Draw();
    }

}