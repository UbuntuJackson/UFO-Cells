#include "level.h"
#include "game.h"
#include "layer.h"
#include "layer_actor.h"
#include "layer_background.h"
#include "layer_solid.h"
#include "layer_terrain.h"
#include "actor_info.h"

Level::Level() : loading_progress{0}{}

Layer*
Level::NewLayer(std::string _name, std::string _type, std::string _path){
    if(_type == "background"){
        return new LayerBackground(level,_name, _type, _path);
    }
    if(_type == "collision"){
        
        return new LayerSolid(level,_name, _type, _path);
    }
    if(_type == "terrain"){
        return new LayerTerrain(level,_name, _type, _path);
    }
}

Layer*
Level::NewLayer(std::string _name, std::string _type, std::vector<ActorInfo> _layer_info){
    if(_type == "actor"){
        return new LayerActor(level ,_name, _type, _layer_info, registry);
    }
}

Layer*
Level::GetLayer(std::string _layer_name){
    for(auto *layer : layers){
        if(layer->name == _layer_name) return layer;
    }
    return nullptr;
}

void
Level::NewActor(std::string _actor_type ,int _x, int _y, std::string _layer_tag){
    std::cout << "NewActor base-class" << std::endl;
}

void
Level::RemoveActor(int _actor_id){
    for(int i = 0; i < actors.size(); i++){
        if(actors[i]->GetID() == _actor_id){
            delete actors[i];
            actors.erase(actors.begin() + i);
        }
    }
}

void
Level::DeferActorRemoval(int _actor_id){
    std::cout << "Deferred actor-removal with id: " << _actor_id << std::endl;
    deferred_actor_removals.push_back(_actor_id);
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
    deferred_actor_removals.clear();
    for(auto layer : layers){
        layer->Update();
    }
    for(auto act_id : deferred_actor_removals){
        RemoveActor(act_id);
    }
}

void
Level::Draw(Camera* _camera){
    for(auto layer : layers){
        layer->Draw(_camera);
    }
}