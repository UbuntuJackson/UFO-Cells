#ifndef UFO_LOAD_H
#define UFO_LOAD_H
#include <vector>
#include <string>
class Game;
class CellMap;

class UfoLoad{
private:
    Game* game;
    CellMap* map;

    std::vector<LayerInfo> layer_information;

    int asset_index;
    //std::string current_data = "";
    //std::string former_data = "";
    //bool layers_are_added = false;
    std::string loading_screen_dir;
public:
    Layer* NewLayer(std::string _layer, std::string _name, std::string _type, std::string _path);
    Layer* NewLayer(std::string _layer, std::string _name, std::string _type, ActorInfo _actor_info);
    void Set(std::string _data, CellMap* _map);
    void Update();
};

#endif