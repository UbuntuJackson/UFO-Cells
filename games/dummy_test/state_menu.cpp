#include "state_menu.h"
#include <string>
#include <iostream>
#include "../../src/ufo/game.h"
#include "../../src/program/ufo_global.h"
#include <squirrel.h>
#include <sqstdio.h>
#include <sqstdsystem.h>
#include <sqstdmath.h>
#include <sqstdstring.h>

StateMenu::StateMenu(Game* _game): State(_game){
    //std::string path = "../games/" + UfoGlobal::game->game_dir_name + "/scripts/menus.nut";
    //sqstd_dofile(UfoGlobal::game->vm, path.c_str(), 0, 1);
}

void StateMenu::Set(std::string _data){
    menu_string = _data;


}

std::string StateMenu::GetData(){
    return menu_string;
}

void StateMenu::Update(){
    if(UfoGlobal::game->GetKey(olc::Key::R).bPressed){
        UfoGlobal::game->record_input = !UfoGlobal::game->record_input;
        if(UfoGlobal::game->record_input) std::cout << "input recording enabled" << std::endl;
        else std::cout << "input recording disabled" << std::endl;
    }
    //if(UfoGlobal::program.GetKey(olc::Key::S).bPressed) UfoGlobal::program.record_input = true;
    std::string path = "../games/dummy_test/scripts/update_menus.nut";
    sqstd_dofile(UfoGlobal::game->vm, path.c_str(), 0, 1);
}