#ifndef DUMMY_H
#define DUMMY_H
#include "../ufo/camera.h"
#include "../ufo/cell_actor.h"
#include <string>
class Dummy : public CellActor{
public:
    int i = 0;
    std::string solid_layer = "solid";
    Dummy(olc::vf2d _position);
    void Update();
    void Draw();
    void AdjustCollisionX();
    void AdjustCollisionY();
    void AdjustSnapToGround();
    void AdjustHeightOverlap();
};

#endif