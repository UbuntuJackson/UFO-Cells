#ifndef TYPE_REGISTRY_H
#define TYPE_REGISTRY_H

class CellActor;
class Layer;
#include <string>
#include "../../external/olcPixelGameEngine.h"
class TypeRegistry{
public:
    TypeRegistry();
    virtual CellActor* NewActor(std::string _actor, olc::vf2d _position);
};

#endif