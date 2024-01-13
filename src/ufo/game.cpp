#define OLC_PGE_APPLICATION
#include "game.h"
#include <squirrel.h>
#include <sqstdio.h>
#include <sqstdsystem.h>
#include <sqstdmath.h>
#include <sqstdstring.h>
#include "../scripting/wrapper.h"

Game::Game()
{
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

Game::~Game(){
    //for(auto ent : entities){
    //    delete ent;
    //}
    sq_close(vm);
}

bool Game::OnUserCreate(){
    LoadResources();
    return true;
}

bool Game::OnUserUpdate(float fElapsedTime){
    dt = fElapsedTime;
    Clear(olc::GREY);
    SetPixelMode(olc::Pixel::NORMAL);

    game_state->Update();

    SetPixelMode(olc::Pixel::NORMAL);
    return running;
}

void Game::SetState(std::string _state, std::string _data){
    game_state = game_states[_state];
    game_state->Set(_data);
}

void Game::LoadResources(){

}