#ifndef FUNCITON_OBJECT_H
#define FUNCITON_OBJECT_H
#include <functional>
#include "fundamental.h"

class FunctionObject : public Fundamental{
    std::function<void()> fun;
    FunctionObject(std::function<void()> _fun) : fun{_fun}{}
    void Update();
};

#endif