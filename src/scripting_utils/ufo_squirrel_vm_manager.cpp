#include "../ufo/game.h"
#include "../ufo/state.h"
#include <string>
#include <squirrel.h>
#include <sqstdio.h>
#include <sqstdsystem.h>
#include <sqstdmath.h>
#include <sqstdstring.h>
#include "../scripting/wrapper.h"
#include "ufo_squirrel_vm_manager.h"

UfoSquirrelVM_Manager::UfoSquirrelVM_Manager(){
    vm = sq_open(1024);

    sq_pushroottable(vm);
    sqstd_register_iolib(vm);
    sqstd_register_systemlib(vm);
    sqstd_register_mathlib(vm);
    sqstd_register_stringlib(vm);

    UfoAPI::register_ufo_wrapper(vm);
}
template<typename T, typename... Args>
void
UfoSquirrelVM_Manager::CallSquirrelFunction(std::string _func, T _t, Args... _args){
    //sq_pushroottable(vm);
    sq_pushstring(vm, "foo", -1);
}
