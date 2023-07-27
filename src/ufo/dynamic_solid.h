#ifndef DYNAMIC_SOLID_H
#define DYNAMIC_SOLID_H
#include "cell_actor.h"
#include <string>
#include "../../external/olcPixelGameEngine.h"

class DynamicSolid : public CellActor{
public:
    //std::string mask;
    int timelapse;
    DynamicSolid(olc::vf2d _position, std::string _mask);
    void Update();
    void Draw();
};
#endif