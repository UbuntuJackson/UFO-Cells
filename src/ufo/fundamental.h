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

    std::string name = "";

    Fundamental(){}
    Fundamental(std::string _name) : name{_name}{}

    template<typename T, typename ... Args>
    T* Attach(Args ...args){
        T *node = new T(args ...);
        node->parent = this;
        nodes.push_back(node);
        return node;
    }
    virtual void Update(){}
    void UpdateCallbacks(){
        Console::Out(name, "Update");
        Update();
        for(int i = 0; i < nodes.size(); i++){
            nodes[i]->UpdateCallbacks();
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