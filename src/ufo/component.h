#ifndef COMPONENT_H
#define COMPONENT_H
#include <vector>
#include <utility>
#include "console.h"
#include <string>
#include "../../external/olcPixelGameEngine.h"
class Scene;

class Component{
public:
    Component* parent = nullptr;
    Scene* scene_ptr;
    std::vector<Component*> nodes;
    olc::vf2d position;
    int id;
    std::string name = "";

    Component(){}
    Component(std::string _name);

    template<typename tNode>
    tNode* Attach(tNode* _node){
        _node->parent = this;
        nodes.push_back(_node);
        return _node;
    }

    virtual void OnReady();
    virtual void SuperOnReady();
    virtual void SuperUpdate();
    virtual void SuperDraw();
    virtual void Update();
    virtual void Draw();

    void PrintTree(int _depth = 0);
    void UpdateCallbacks();
    void DrawCallbacks();
    ~Component();
};

#endif