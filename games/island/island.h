#ifndef ISLAND_H
#define ISLAND_H
#include "../../src/ufo/state.h"
#include "../../src/ufo/game.h"
#include "../../src/ufo/cellmap.h"
#include "../../src/ufo/camera.h"
#include "../../src/ufo/ufo_load.h"

class CustomTypeRegistry;
class Island : public Game{
public:
    Camera camera;
    CellMap map;
    State play;
    State inventory;
    State menu;
    UfoLoad load;
    CustomTypeRegistry *registry;
    Island();
    void LoadResources();
};

#endif