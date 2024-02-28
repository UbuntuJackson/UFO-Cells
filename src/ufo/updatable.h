#ifndef UPDATABLE_H
#define UPDATABLE_H
#include "component.h"

class Updatable : public Component{
public:
    Updatable() = default;
    virtual void SuperOnReady();
    virtual void SuperUpdate();
    virtual void SuperDraw();
    virtual void OnReady();
    virtual void Update();
    virtual void Draw();
};

#endif