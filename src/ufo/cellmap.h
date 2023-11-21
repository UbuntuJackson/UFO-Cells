#ifndef CELLMAP_H
#define CELLMAP_H
#include <vector>
#include "../../external/olcPixelGameEngine.h"
#include <string>
#include "layer.h"

class Game;
class CellActor;

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
    std::vector<int> deferred_actor_removals;
    virtual void NewActor(std::string _actor_type ,int _x, int _y, std::string _layer_tag);
    virtual void RemoveActor(int _actor_id);
    CellMap() = default;
    CellMap(Game* _game);
    ~CellMap();
    Layer* GetLayer(std::string _layer_name);
    void LoadMap(std::string _map_path);
    void UnloadMap();
    void DeferActorRemoval(int _actor_id);
    void Update();
    void Draw(Camera* _camera);

};

#endif