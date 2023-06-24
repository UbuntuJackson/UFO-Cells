#define OLC_PGE_APPLICATION
#include "program.h"
#include "entity.h"
#include <iostream>
#include "dummy.h"

Program::Program(){
    sAppName = "cell";
}

Program::~Program(){
    for(auto ent : entities){
        delete ent;
    }
}

bool Program::OnUserCreate(){
    asset_manager.LoadAssets();
    entities.push_back(new Dummy(this, olc::vf2d(50.0f, 50.0f)));
    
    return true;
}
bool Program::OnUserUpdate(float fElapsedTime){
    Clear(olc::DARK_BLUE);
    SetPixelMode(olc::Pixel::NORMAL);
    DrawDecal(
        olc::vf2d(0.0f, 0.0f),
        asset_manager.decMap, olc::vf2d(1.0f, 1.0f));
    for(auto e : entities){
        e->Update();
    }
    for(auto &e : entities){
        e->Draw();
    }
    SetPixelMode(olc::Pixel::NORMAL);
    return true;
}