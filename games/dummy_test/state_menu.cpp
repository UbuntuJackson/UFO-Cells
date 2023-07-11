#include "state_menu.h"
#include <string>
#include "../../src/ufo/game.h"
#include "../../src/program/ufo_global.h"
#include <squirrel.h>
#include <sqstdio.h>
#include <sqstdsystem.h>
#include <sqstdmath.h>
#include <sqstdstring.h>

StateMenu::StateMenu(): State(){
    std::string path = "../games/" + UfoGlobal::program.game_dir_name + "/scripts/menus.nut";
    sqstd_dofile(UfoGlobal::program.vm, path.c_str(), 0, 1);
}

void StateMenu::SetMenu(std::string _map){
}

void StateMenu::Update(){
    std::string path = "../games/dummy_test/scripts/update_menus.nut";
    sqstd_dofile(UfoGlobal::program.vm, path.c_str(), 0, 1);
}