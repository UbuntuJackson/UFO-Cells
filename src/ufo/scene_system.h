#ifndef SCENE_SYSTEM_H
#define SCENE_SYSTEM_H
#include <vector>
#include <memory>
#include "scene.h"
class Game;

class SceneSystem{
public:
    Game* game;
    SceneSystem() = default;
    std::vector<std::unique_ptr<Scene>> scenes;

    template<typename tScene, typename ...tArgs>
    void NewScene(tArgs ... _args){
        scenes.push_back(std::make_unique<tScene>(_args...));
    }

    template<typename tScene, typename ...tArgs>
    void LoadScene(std::string _path, tArgs ... _args){
        scenes.push_back(std::make_unique<tScene>(_args...));
        scenes.back()->Load(_path);
    }

    template<typename tScene, typename ...tArgs>
    void ReplaceScene(tArgs ..._args){
        scenes.pop_back();
        scenes.push_back(_args...);
    }
    
    void GotoScene(std::string _scene_name);
    void RemoveActiveScene();

    Scene* GetActiveScene();

    void Update();
};

#endif