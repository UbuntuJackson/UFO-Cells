#ifndef CUSTOM_TYPE_REGISTRY_H
#define CUSTOM_TYPE_REGISTRY_H

class CellActor;
class Layer;
class Island;
#include <string>
#include "../../src/ufo/type_registry.h"
#include "../../external/olcPixelGameEngine.h"
class CustomTypeRegistry : public TypeRegistry{
public:
    Island *game;
    CustomTypeRegistry(Island* _game);
    CellActor* NewActor(std::string _actor, olc::vf2d _position);
};

#endif