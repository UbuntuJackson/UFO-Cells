#include "scene.h"
#include "json_interface.h"
#include <string>

Scene::Scene(std::string _name) : name{_name}{
    //default scene
}

void
Scene::SuperOnReady(){

}

void
Scene::OnReady(){}


void
Scene::UpdateSceneBundle(){}

void
Scene::UpdateGeometry(){}

void
Scene::UpdateTilemap(){}

void
Scene::UpdateScene(){
    UpdateSceneBundle();
    UpdateGeometry();
    UpdateGeometry();
}

void
Scene::DeferActorRemoval(){

}

void
Scene::Load(std::string _path){
    //CustomLoad(_json);
}

void
Scene::CustomLoad(ujson::JsonNode _json){}