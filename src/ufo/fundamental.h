#ifndef FUNDAMENTAL_H
#define FUNDAMENTAL_H
#include <vector>
#include <utility>
#include "console.h"
#include <string>
class Fundamental{
public:
    Fundamental* parent = nullptr;
    std::vector<Fundamental*> nodes;

    int depth = 0;
    std::string name = "";

    Fundamental(){}
    Fundamental(std::string _name) : name{_name}{}

    template<typename T, typename ... Args>
    T* Attach(Args ...args){
        T *node = new T(args ...);
        node->parent = this;
        nodes.push_back(node);

        //for debugging

        node->depth = depth+1;
        return node;
    }

    void PrintTree(int _depth = 0){
        std::string indent = "";
        for(int _ = 0; _ < _depth; _++) indent += std::string("    ");
        Console::Out(std::string(indent) + " " + name);
        for(auto node : nodes){
            node->PrintTree(_depth+1);
        }
    }

    virtual void Update(){}
    void UpdateCallbacks(){
        Console::Out(name, "Update");
        Update();
        for(int i = 0; i < nodes.size(); i++){
            nodes[i]->UpdateCallbacks();
        }
    }
    void DrawCallbacks(){
        Console::Out(name, "Draw");
        Update();
        for(int i = 0; i < nodes.size(); i++){
            nodes[i]->DrawCallbacks();
        }
    }
    ~Fundamental(){
        for(auto node : nodes){
            delete node;
        }
        Console::Out(name, "Destructor");
    }
};

#endif