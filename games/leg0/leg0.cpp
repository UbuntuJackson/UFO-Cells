#include "leg0.h"
#include "../../src/ufo/state.h"
#include <squirrel.h>
#include "state_default.h"

Leg0::Leg0():Game(){
    game_state = new StateDefault(this);
}

Leg0::~Leg0(){
    delete game_state;
}

void
Leg0::LoadResources(){
    asset_manager.LoadDecal("../games/leg0/res/snowman.png", "snowman");
}
