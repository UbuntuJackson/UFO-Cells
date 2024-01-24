#include <functional>
#include "function_object.h"

FunctionObject::FunctionObject(std::function<void()> _fun) : fun{_fun}{}

void
FunctionObject::Update(){
    fun();
}