#ifndef COMPONENT_WRAPPER_H
#define COMPONENT_WRAPPER_H
#include "component.h"

template<class tType>
class ComponentWrapper : public Component{
public:
    tType *component;
    ComponentWrapper(tType* _t){
        component = _t;
    }
    tType* GetComponent(){return component;}
};

#endif