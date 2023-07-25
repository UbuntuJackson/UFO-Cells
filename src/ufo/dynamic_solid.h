#ifndef DYNAMIC_SOLID_H
#define DYNAMIC_SOLID_H
#include "cell_actor.h"
#include <string>

class DynamicSolid : public CellActor{
    DynamicSolid(std::string _mask);
    void Update();
    void Draw();
};
#endif