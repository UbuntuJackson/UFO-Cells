#define OLC_PGE_APPLICATION

#include <iostream>
#include "../../games/dummy_test/dummy.h"
#include "../scripting/wrapper.h"
#include <string>
#include <squirrel.h>
#include <sqstdio.h>
#include <sqstdsystem.h>
#include <sqstdmath.h>
#include <sqstdstring.h>

Program::Program(){
    sAppName = "UFO-Cells";
    game_dir_name = "dummy_test";
    vm = sq_open(1024);

    sq_pushroottable(vm);
    sqstd_register_iolib(vm);
    sqstd_register_systemlib(vm);
    sqstd_register_mathlib(vm);
    sqstd_register_stringlib(vm);

    UfoAPI::register_ufo_wrapper(vm);
}

Program::~Program(){
    for(auto ent : entities){
        delete ent;
    }
    sq_close(vm);
}
void Program::SetGame(Game* _game){
    game = _game;
}

bool Program::OnUserCreate(){
    game->LoadResources();
    return true;
}
bool Program::OnUserUpdate(float fElapsedTime){
    dt = fElapsedTime;
    Clear(olc::GREY);
    SetPixelMode(olc::Pixel::NORMAL);

    game->game_state->Update();

    SetPixelMode(olc::Pixel::NORMAL);
    return running;
}