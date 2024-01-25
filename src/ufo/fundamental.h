#ifndef FUNDAMENTAL_H
#define FUNDAMENTAL_H
#include <vector>
#include <utility>
#include "console.h"
class Fundamental{
public:
    Fundamental* parent = nullptr;
    std::vector<Fundamental*> nodes;
    bool is_attached_anonymously = true;
    Fundamental(){}

    Fundamental& operator=(const Fundamental& f){
        is_attached_anonymously = false;
        return *this;
    }

    template<typename T, typename ... Args>
    T& Attach(Args ...args){
        T *node = new T(args ...);
        node->parent = this;
        nodes.push_back(node);
        return *node;
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
    void AttemptPointerDelete(){
        if(is_attached_anonymously){
            for(auto node : nodes){
                node->AttemptPointerDelete();
                delete node;
            }
        }
    }
    ~Fundamental(){
        AttemptPointerDelete();
        Console::Out("Destructor");
    }
};

#endif