#ifndef FUNDAMENTAL_H
#define FUNDAMENTAL_H
#include <vector>
#include <utility>
#include "console.h"
class Fundamental{
public:
    Fundamental* parent = nullptr;
    std::vector<Fundamental*> nodes;
    Fundamental(){}
    template<typename T, typename ... Args>
    T Attach(Args ...args){
        T node = T(args ...);
        node.parent = this;
        nodes.push_back(&node);
        return node;
    }
    void Update(){
        Console::Out("hello from Fundamental");
    }
    void UpdateCallbacks(){
        Update();
        for(auto &node : nodes){
            node->UpdateCallbacks();
        }
    }
};

#endif