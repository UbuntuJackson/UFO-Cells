#ifndef UFO_SQUIRREL_VM_MANAGER_H
#define UFO_SQUIRREL_VM_MANAGER_H
#include <squirrel.h>

class UfoSquirrelVM_Manager{
public:
    HSQUIRRELVM vm;
    UfoSquirrelVM_Manager();
    template<typename T, typename... Args>
    void CallSquirrelFunction(std::string _func, T _t, Args... _args);
};

#endif