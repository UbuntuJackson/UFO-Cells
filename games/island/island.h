#ifndef ISLAND_H
#define ISLAND_H
#include "../../src/ufo/state.h"
#include "../../src/ufo/game.h"
#include "../../src/ufo/cellmap.h"
#include "../../src/ufo/camera.h"
#include "../../src/ufo/ufo_load.h"
#include "state_load.h"
#include "state_play.h"

class CustomTypeRegistry;
class Island : public Game{
public:
    Camera camera;
    CellMap map;
    StatePlay play;
    State inventory;
    State menu;
    StateLoad load;
    CustomTypeRegistry *registry;
    Island();
    void LoadResources();
};

#endif