#ifndef DUMMY_H
#define DUMMY_H
#include "../../src/ufo/camera.h"
#include "../../src/ufo/cell_actor.h"
#include <string>
class Dummy : public CellActor{
public:
    int i = 0;
    std::string solid_layer = "solid";
    bool is_already_in_semi_solid = false;
    olc::vf2d former_position;
    Dummy(olc::vf2d _position);
    void Update();
    void Draw();
    void AdjustCollisionX();
    void AdjustCollisionY();
    void AdjustDownSlope();
    void AdjustUpSlope();
};

#endif