#ifndef DUMMY_TEST_GAME_H
#define DUMMY_TEST_GAME_H
#include "state_load.h"
#include "state_menu.h"
#include "state_play.h"
#include "../../src/ufo/game.h"

class DummyTestGame : public Game{
public:
    StateLoad *state_load;
    StateMenu *state_menu;
    StatePlay *state_play;
    DummyTestGame();
    ~DummyTestGame();

};

#endif