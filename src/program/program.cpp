#define OLC_PGE_APPLICATION
#include "program.h"
#include <iostream>
#include "../dummy_test/dummy.h"

Program::Program(){
    sAppName = "cell";
}

Program::~Program(){
    for(auto ent : entities){
        delete ent;
    }
}

bool Program::OnUserCreate(){
    camera = Camera(this);
    cell_map = CellMap(this);
    asset_manager.LoadAssets();
    entities.push_back(new Dummy(this, olc::vf2d(50.0f, 50.0f)));
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