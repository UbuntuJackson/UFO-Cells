#ifndef ISLAND_H
#define ISLAND_H
#include "../../src/ufo/state.h"
#include "../../src/ufo/game.h"
#include "../../src/ufo/cellmap.h"
#include "../../src/ufo/camera.h"

class Island : public Game{
public:
    Camera camera;
    CellMap map;
    State play;
    State inventory;
    State load;
    State menu;
    Island();
};

#endif