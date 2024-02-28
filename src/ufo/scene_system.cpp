#include "scene_system.h"
#include <string>
#include "scene.h"
#include <cassert>
void
SceneSystem::GotoScene(std::string _scene_name){}

void
SceneSystem::RemoveActiveScene(){}

Scene*
SceneSystem::GetActiveScene(){
    assert(scenes.size() > 0);

    return scenes.back().get();
}

void
SceneSystem::Update(){
    scenes[scenes.size()-1]->UpdateScene();
    scenes[scenes.size()-1]->DrawScene();
}