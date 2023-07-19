#ifndef DUMMY_TEST_GAME_H
#define DUMMY_TEST_GAME_H
#include "state_load.h"
#include "state_menu.h"
#include "state_play.h"
#include "../../src/ufo/game.h"
#include "../../external/olcPixelGameEngine.h"

class DummyTestGame : public Game{
public:
    const olc::Pixel SEMI_SOLID_COLOUR = olc::Pixel(255, 0, 255, 255);
    const olc::Pixel SOLID_COLOUR = olc::Pixel(255, 255, 255, 255);
    StateLoad *state_load;
    StateMenu *state_menu;
    StatePlay *state_play;
    DummyTestGame();
    ~DummyTestGame();

};

#endif