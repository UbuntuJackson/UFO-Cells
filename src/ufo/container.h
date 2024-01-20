#ifndef CONTAINER_H
#define CONTAINER_H

#include <vector>
#include <memory>
#include <functional>
#include <utility>

template<typename T>
class Container{
public:
    Level* level;
    std::vector<T*> container;
    std::function<void(int)> remove_ptr = [&](int _id){
        for(int i = 0; i < container.size(); i++){
            if(container[i]->GetID() == _id){
                container.erase(container.begin() + i);
            }
        }
    };
    Container(Level* _level) : level{_level}{}
    T* GetByID(int _id){
        for(auto p : container){
            if(p->GetID() == _id) return p;
        }
        return nullptr;
    }
    template<typename ...Args>
    T* New(Args ...args){
        std::unique_ptr<T> instance = std::make_unique<T>(args ...);
        container.push_back(instance.get());
        level->actors.push_back(std::move(instance));
    }
};

#endif