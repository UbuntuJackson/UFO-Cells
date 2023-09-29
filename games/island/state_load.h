#ifndef STATE_LOAD_H
#define STATE_LOAD_H

#include "../../src/ufo/ufo_load.h"


class Island;

class StateLoad : public UfoLoad{
    Island* game;
public:
    StateLoad() = default;
    StateLoad(Island *_game,CellMap* _map, TypeRegistry *_registry);
    void OnLoadFinished();
};

#endif