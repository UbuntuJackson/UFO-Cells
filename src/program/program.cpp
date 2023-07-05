#define OLC_PGE_APPLICATION

#include "program.h"
#include <iostream>
#include "../dummy_test/dummy.h"
#include "../scripting/wrapper.h"
#include <string>
#include <squirrel.h>
#include <sqstdio.h>
#include <sqstdsystem.h>
#include <sqstdmath.h>
#include <sqstdstring.h>

Program::Program(){
    sAppName = "UFO-Cells";
    vm = sq_open(1024);

    sq_pushroottable(vm);
    sqstd_register_iolib(vm);
    sqstd_register_systemlib(vm);
    sqstd_register_mathlib(vm);
    sqstd_register_stringlib(vm);

    UfoAPI::register_ufo_wrapper(vm);

    std::string path = "../src/dummy_test/scripts/test.nut";
    sqstd_dofile(vm, path.c_str(), 0, 1);
}

Program::~Program(){
    for(auto ent : entities){
        delete ent;
    }
    sq_close(vm);
}

bool Program::OnUserCreate(){
    camera = Camera();
    cell_map = CellMap();
    asset_manager.LoadAssets();
    entities.push_back(new Dummy(olc::vf2d(450.0f, 50.0f)));
    cell_map.LoadMap("../res/map/windmill/windmill.json");

    return true;
}
bool Program::OnUserUpdate(float fElapsedTime){
    Clear(olc::GREY);
    SetPixelMode(olc::Pixel::NORMAL);

    for(auto e : entities){
        e->Update();
    }

    cell_map.Draw();

    SetPixelMode(olc::Pixel::NORMAL);
    return true;
}