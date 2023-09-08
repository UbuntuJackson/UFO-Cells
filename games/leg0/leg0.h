#ifndef LEG0_H
#define LEG0_H
#include "../../src/ufo/game.h"
#include "../../src/ufo/state.h"
#include "../../src/ufo/camera.h"
#include "anim_snowman.h"

class Leg0 : public Game{
public:
    Leg0();
    ~Leg0();
    Camera camera;
    AnimSnowman anim_snowman;
    void LoadResources();
};

#endif