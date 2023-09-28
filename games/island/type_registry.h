#ifndef TYPE_REGISTRY_H
#define TYPE_REGISTRY_H

class CellActor;
class Layer;
class Island;
#include <string>

class TypeRegistry{
public:
    Island *game;
    TypeRegistry() = default;
    CellActor* NewActor(std::string _actor);
    Layer* NewLayer(std::string _layer, std::string _name, std::string _type, std::string _path);
    Layer* NewLayer(std::string _layer, std::string _name, std::string _type, ActorInfo _actor_info);
};

#endif