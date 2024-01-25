#ifndef FUNDAMENTAL_H
#define FUNDAMENTAL_H
#include <vector>
#include <utility>
#include <memory>
#include "console.h"
class Fundamental{
public:
    Fundamental* parent = nullptr;
    std::vector<std::unique_ptr<Fundamental>> nodes;
    Fundamental(){}
    template<typename T, typename ... Args>
    T& Attach(Args ...args){
        std::unique_ptr<T> node = std::make_unique<T>(args ...);
        node->parent = this;
        nodes.push_back(std::move(node));
        return *(node.get());
    }
    virtual void Update(){
        Console::Out("hello from Fundamental");
    }
    void UpdateCallbacks(){
        Update();
        for(int i = 0; i < nodes.size(); i++){
            std::cout << this << std::endl;
            nodes[i]->UpdateCallbacks();
        }
        Console::Out("hello from UpdateCallbacks");
    }
};

#endif