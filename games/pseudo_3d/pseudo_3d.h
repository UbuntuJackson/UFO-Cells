#ifndef LEG0_H
#define LEG0_H
#include "../../src/ufo/game.h"
#include "../../src/ufo/state.h"
#include "../../src/ufo/camera.h"
#include "../../external/olcPixelGameEngine.h"

class Pseudo3d : public Game{
public:
    olc::vf2d position;

    olc::vf2d near_0;
    olc::vf2d near_1;
    olc::vf2d far_0;
    olc::vf2d far_1;
    float dy;
    float dx;
    float depth;

    Pseudo3d();
    ~Pseudo3d();
    Camera camera;
    void LoadResources();
    bool OnUserCreate();
    bool OnUserUpdate(float fElapsedTime);
};

#endif