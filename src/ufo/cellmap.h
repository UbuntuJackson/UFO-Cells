#ifndef CELLMAP_H
#define CELLMAP_H
#include <vector>
#include "../../external/olcPixelGameEngine.h"
#include <string>
#include "layer.h"

class Game;

class CellMap{
public:
    Game* game;
    olc::vf2d map_size;
    std::string map_path;
    std::map<std::string ,olc::Sprite*> map_sprites;
    std::map<std::string, olc::Decal*> map_decals;
    std::vector<Layer*> layers;
    std::vector<olc::Decal*> visible_layers;
    std::map<std::string, olc::Decal*> collision_layers;

    //Actors tagged with a layer
    std::vector<CellActor*> actors;
    virtual void NewActor(std::string _actor_type ,float _x, float _y, std::string _layer_tag) = 0;
    virtual void RemoveActor(std::string _actor_id) = 0;
    CellMap() = default;
    CellMap(Game* _game);
    ~CellMap();
    Layer* GetLayer(std::string _layer_name);
    void LoadMap(std::string _map_path);
    void UnloadMap();
    void Draw(Camera* _camera);

};

#endif