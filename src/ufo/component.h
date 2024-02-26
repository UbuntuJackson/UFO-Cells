#ifndef COMPONENT_H
#define COMPONENT_H
#include <vector>
#include <utility>
#include "console.h"
#include <string>

class Component{
public:
    Component* parent = nullptr;
    std::vector<Component*> nodes;
    olc::vf2d position;
    int id;
    std::string name = "";

    Component(){}
    Component(std::string _name);

    template<typename tNode, typename ... Args>
    tNode* Attach(Args ...args){
        tNode* node = scene_ptr->NewActor<tNode>(args...);
        node->parent = this;
        nodes.push_back(node);
        return node;
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