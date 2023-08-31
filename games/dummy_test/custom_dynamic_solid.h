#ifndef CUSTOM_DYNAMIC_SOLID
#define CUSTOM_DYNAMIC_SOLID
#include "../../src/ufo/dynamic_solid.h"
#include "dummy_test_game.h"

class CustomDynamicSolid : public DynamicSolid{
public:
    DummyTestGame* game;
    CustomDynamicSolid(olc::vf2d _position, DummyTestGame* _game, std::string _mask);
    void Draw();
};
#endif