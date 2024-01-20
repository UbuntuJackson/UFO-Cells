#ifndef CONTAINER_H
#define CONTAINER_H

#include <vector>
#include <memory>
#include <functional>

template<typename T>
class Container{
public:
    Level* _level;
    std::vector<T*> container;
    std::function<void(int)> remove_ptr = [&this](int _id){
        for(int i = 0; i < container.size(); i++){
            if(container[i]->GetID() == _actor_id){
                container.erase(container.begin() + i);
            }
        }
    }
    Container(Level* _level) : level{_level}{}
    T* GetByID(int _id){
        for(auto p : container){
            if(p->GetID() == _id) return p;
        }
        return nullptr;
    }
    template<typename ... Args>
    T* New(Args ...args){
        std::unique_ptr instance = std::make_unique<T>(args ..., remove_ptr);
        container.push_back(instance.get());
        level.push_back(std::move(instance));
    }
};

#endif