#include <filesystem>
#include "cellmap.h"
#include <string>
#include <fstream>
#include "../external/cJSON.h"
#include "file_utils.h"
#include "olcPixelGameEngine.h"
#include "program.h"

CellMap::CellMap(Program *_program) : program{_program},map_path {""}{}

void
CellMap::LoadMap(std::string _map_path){
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
        std::cout << (type == "collision") << std::endl;
        if(type == "collision"){
            std::cout << "true" << std::endl;
            olc::Sprite *spr = new olc::Sprite(path);
            olc::Decal *dec = new olc::Decal(spr);
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
    for(auto dec : visible_layers){
        delete dec;
    }
    visible_layers.clear();
    for(auto [key, dec] : collision_layers){
        delete dec;
    }
    collision_layers.clear();
}

CellMap::~CellMap(){UnloadMap();}

void
CellMap::Draw(){
    for(auto dec : visible_layers){
        program->DrawDecal(
            olc::vf2d(0.0f, 0.0f),
            dec, olc::vf2d(1.0f, 1.0f));
    }
    
}