#ifndef FUNDAMENTAL_H
#define FUNDAMENTAL_H
#include <vector>
#include <utility>
class Fundamental{
    Fundamental* parent = nullptr;
    std::vector<Fundamental*> nodes;
    template<typename T, typename ... Args>
    T Attach(Args ...args){
        T node = T(args ...);
        node.parent = this;
        nodes.push_back(&node);
        return std::move(node);
    }
};

#endif