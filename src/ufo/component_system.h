#ifndef COMPONTENT_SYSTEM
#define COMPONTENT_SYSTEM
#include <unordered_map>
#include <vector>

//...

class ComponentSystem{
    std::unordered_map<Component*> components;
};

#endif