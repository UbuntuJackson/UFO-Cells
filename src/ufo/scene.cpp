#include "scene.h"
#include "json_interface.h"
#include <string>
#include "scene_system.h"
#include "ray2.h"
#include "game.h"

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
    for(auto &updatable : updatables){
        updatable->UpdateCallbacks();
    }
}

void
Scene::DrawScene(){
    for(auto &ray : rays){
        scene_system->game->DrawLine(ray->Start(), ray->End());
    }
    for(auto &updatable : updatables){
        updatable->DrawCallbacks();
    }
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