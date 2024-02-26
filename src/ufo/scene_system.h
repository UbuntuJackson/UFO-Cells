#ifndef SCENE_H
#define SCENE_H
#include <vector>
class SceneSystem{

    std::vector<Scene*> scenes;

    template<typename tScene, typename ...tArgs>
    void NewScene(tArgs ... _args){
        scenes.push_back(std::make_unique<tScene>(args...));
    }

    template<typename tScene, typename ...tArgs>
    void LoadScene(std::string _path, tArgs ... _args){
        scenes.push_back(std::make_unique<tScene>(args...));
        scenes.back().Load(_path);
    }

    template<typename tScene, typename ...tArgs>
    void ReplaceScene(){
        scenes.pop_back();
        scenes.push_back(args...);
    }
    
    void GotoScene(std::string _scene_name);
    void RemoveActiveScene();

    void Update();
};

#endif