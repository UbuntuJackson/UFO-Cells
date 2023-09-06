#include "leg0.h"
#include "../../src/ufo/state.h"
#include <squirrel.h>
#include "state_default.h"
#include "../../src/ufo/camera.h"

Leg0::Leg0():Game(), camera{Camera(this)}{
    game_state = new StateDefault(this);
    camera.SetStateMouseAndArrowKeys({0.0f,0.0f}, {3200.0f,1600.0f});
}

Leg0::~Leg0(){
    delete game_state;
}

void
Leg0::LoadResources(){
    asset_manager.LoadDecal("../games/leg0/res/snowman.png", "snowman");
}
