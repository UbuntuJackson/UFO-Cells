#ifndef COMPONENT_WRAPPER_H
#define COMPONENT_WRAPPER_H
#include "component.h"

template<class tType>
class ComponentWrapper : public Component{
public:
    tType component;
    template<typename ...Args>
    ComponentWrapper(Args ..._args) : component{tType(_args...)}{}
    tType& GetComponent(){return component;}
};

#endif