#ifndef UFO_LOAD_H
#define UFO_LOAD_H
#include <vector>
#include <string>
#include "actor_info.h"
#include "state.h"
class Game;
class CellMap;
class TypeRegistry;
class Layer;

class UfoLoad : public State{
private:

    int asset_index;
    //std::string current_data = "";
    //std::string former_data = "";
    //bool layers_are_added = false;
    std::string loading_screen_dir;
public:
    Game* game;
    CellMap* map;
    TypeRegistry* registry;
    UfoLoad() = default;
    UfoLoad(Game* game, TypeRegistry *_registry);
    Layer* NewLayer(std::string _name, std::string _type, std::string _path);
    Layer* NewLayer(std::string _name, std::string _type, std::vector<ActorInfo> _layer_info);
    void Set(std::string _data, CellMap* _map);
    void Update();
};

#endif