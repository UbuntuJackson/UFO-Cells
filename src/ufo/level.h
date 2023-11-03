#ifndef MAP_H
#define MAP_H
#include <map>
#include "../../external/olcPixelGameEngine.h"
#include <vector>
#include <string>
class Layer;
class Game;
class Level{
    Game* game;
    int loading_progress;
    olc::vf2d level_size;
    std::string level_path;
    std::map<std::string ,olc::Sprite*> level_sprites;
    std::map<std::string, olc::Decal*> level_decals;
    std::vector<Layer*> layers;
    std::vector<olc::Decal*> visible_layers;
    std::map<std::string, olc::Decal*> collision_layers;
    Level() = default;
    Level(Game* _game);
    Layer* GetLayer(std::string _layer_name);
    Layer* NewLayer()
    CellActor NewActor(std::string _actor, olc::vf2d _position);
    bool ReadLevelFromFile(std::string _path);
    bool Load();
    void Update();
    void Draw(Camera* _camera);
};

#endif