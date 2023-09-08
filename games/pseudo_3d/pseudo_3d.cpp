#include "pseudo_3d.h"
#include "../../src/ufo/state.h"
//#include "state_default.h"
#include "../../src/ufo/camera.h"

Pseudo3d::Pseudo3d():Game(), camera{Camera(this)}{
    //game_state = new StateDefault(this);
    camera.SetStateMouseAndArrowKeys({0.0f,0.0f}, {3200.0f,1600.0f});
}

bool
Pseudo3d::OnUserCreate(){
    LoadResources();
    position = {0.0f,0.0f};
    near_0 = {0.0f, 0.0f};
    near_1 = {(float)ScreenWidth(), 0.0f};
    far_0 = {0.0f-200.0f, 100.0f};
    far_1 = {(float)ScreenWidth()+200.0f, 100.0f};

    dy = (far_0.y - near_0.y)/(far_0.x - near_0.x);
    dx = (far_0.x - near_0.x)/(far_0.y - near_0.y);    
    depth = 100.0f;

    return true;
}

bool
Pseudo3d::OnUserUpdate(float fElapsedTime){
    Clear(olc::GREY);
    if(GetKey(olc::RIGHT).bHeld) position.x += 5.0f;
    if(GetKey(olc::LEFT).bHeld) position.x -= 5.0f;
    if(GetKey(olc::UP).bHeld) position.y += 5.0f;
    if(GetKey(olc::DOWN).bHeld) position.y -= 5.0f;
    near_0 = {position.x - (float)(ScreenWidth()/2.0f), position.y};
    near_1 = {position.x + (float)(ScreenWidth()/2.0f), position.y};
    far_0 = {near_0.x-(float)(ScreenWidth()/2.0f), near_0.y+400.0f};
    far_1 = {near_0.x+(float)(ScreenWidth()/2.0f), near_0.y+400.0f};
    dy = (far_0.y - near_0.y)/(far_0.x - near_0.x);
    dx = (far_0.x - near_0.x)/(far_0.y - near_0.y);
    
    std::cout << position.y << std::endl;
    for(int y = 0; y < ScreenHeight(); y++){
        float start_x = near_0.x + dx * y;
        float end_x = near_1.x - dx * y;
        
        for(int x = 0; x < ScreenWidth(); x++){
            Draw(x, ScreenHeight()-y, asset_manager.GetDecal("grid")->sprite->GetPixel(start_x + x*(end_x-start_x)/(near_1.x-near_0.x) ,near_0.y + (float)(y)));
        }
    }

    olc::vf2d obj_pos = {0.0f, 1300.0f};
    float obj_depth = {obj_pos.y-position.y};
    float obj_start_x = {near_0.x - dx * obj_depth};
    float obj_end_x = {near_1.x + dx * obj_depth};
    float nx = (near_1.x-near_0.x)/((obj_end_x-obj_start_x)/(obj_pos.x-position.x));
    float ny = ScreenHeight()-obj_depth;

    DrawDecal({nx, ny}, asset_manager.GetDecal("snowman"));

    return true;
}

Pseudo3d::~Pseudo3d(){
    //delete game_state;
}

void
Pseudo3d::LoadResources(){
    asset_manager.LoadDecal("../games/pseudo_3d/res/grid.png", "grid");
    asset_manager.LoadDecal("../games/leg0/res/snowman.png", "snowman");
}