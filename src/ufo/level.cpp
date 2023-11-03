#include "level.h"
#include "game.h"
#include "layer.h"
#include "actor_info.h"
Level::Level(Game* _game) : game{_game}, loading_progress{0}{}

Layer* Level::GetLayer(){}

Layer* Level::NewLayer(){}

CellActor
Level::NewActor(std::string _actor, olc::vf2d _position){

}

bool
Level::ReadLevelFromFile(std::string _path){
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
            map->layers.push_back(NewLayer(name,type,path));
            std::cout << type << std::endl;
            std::cout << name << std::endl;
            std::cout << path << std::endl;
        }
        if(category == "actor"){
            const cJSON *actor_layer = cJSON_GetObjectItemCaseSensitive(item, "actors");
            std::vector<ActorInfo> layer_information;
            for(int j = 0; j < cJSON_GetArraySize(actor_layer); j++){
                const cJSON *act = cJSON_GetArrayItem(actor_layer, j);
                std::cout << cJSON_GetObjectItemCaseSensitive(act, "actor") -> valuestring << std::endl;
                std::string actor_string = cJSON_GetObjectItemCaseSensitive(act, "actor") -> valuestring;
                int x = cJSON_GetObjectItemCaseSensitive(act, "x") -> valueint;
                int y = cJSON_GetObjectItemCaseSensitive(act, "y") -> valueint;
                std::cout << x << std::endl;
                layer_information.push_back(ActorInfo{actor_string, x, y});

            }
            layers.push_back(NewLayer(name,type,layer_information));
            
        }
    }

    cJSON_Delete(j);
}

bool
Level::Load(){
    if(loading_progress < layers.size()){
        layers[loading_progress]->LoadLayer();
        loading_progress++;
        return true;
    }
    return false;
}

void
Level::Update(){
    for(auto layer : layers){
        layer -> Update();
    }
}

void
Level::Draw(Camera* _camera){
    for(auto layer : layers){
        layer->Draw(_camera);
    }
}