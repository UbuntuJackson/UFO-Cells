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
    CellMap() = default;
    CellMap(Game* _game);
    ~CellMap();
    void LoadMap(std::string _map_path);
    void UnloadMap();
    void Draw(Camera* _camera);

};

#endif