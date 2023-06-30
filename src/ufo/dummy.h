#ifndef DUMMY_H
#define DUMMY_H
#include "camera.h"
#include "cell_actor.h"
#include <string>
class Dummy : public CellActor{
public:
    int i = 0;
    std::string solid_layer = "solid";
    Dummy(Program *_program,olc::vf2d _position);
    void Update();
    void Draw();
    void AdjustCollisionX();
    void AdjustCollisionY();
    void AdjustSnapToGround();
    void AdjustHeightOverlap();
};

#endif