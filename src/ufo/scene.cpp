#include "scene.h"
#include "json_interface.h"

Scene(std::string _name = "Un-named") : name{_name}{
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
Scene::Load(){
    CustomLoad();
}

void
Scene::CustomLoad(){}