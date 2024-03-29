#ifndef MAP_H
#define MAP_H
#include <map>
#include "../../external/olcPixelGameEngine.h"
#include <vector>
#include <string>
#include "actor_info.h"
#include "camera.h"
#include "stack_based_state.h"
#include "json_interface.h"

class Class;
class Layer;
class Game;
class Actor;

class Level : public StackBasedState{
public:
    bool show_solid_layers = false;

    std::vector<Actor*> actors;
    std::vector<Actor*> new_actors;
    std::vector<int> deferred_actor_removals;

    int loading_progress;
    olc::vf2d map_size;
    std::string path;
    std::map<std::string ,olc::Sprite*> level_sprites;
    std::map<std::string, olc::Decal*> level_decals;
    std::vector<Layer*> layers;
    std::vector<olc::Decal*> visible_layers;
    std::map<std::string, olc::Decal*> collision_layers;
    Level() = default;
    Level(std::string _path);
    virtual Layer* NewLayer(std::string _name, std::string _type, std::string _path);
    virtual Layer* NewLayer(std::string _name, std::string _type, std::vector<ActorInfo> _layer_info);
    virtual Layer* GetLayer(std::string _layer_name);
    virtual void NewActor(std::string _actor_type ,int _x, int _y, std::string _layer_tag);
    void RemoveActor(int _actor_id);
    void DeferActorRemoval(int _actor_id);
    bool ReadLevelSegments(std::string _path);
    virtual void OnHeaderCreate(ujson::JsonNode _json);
    virtual void OnActorLayerCreate(ujson::JsonNode _json);
    virtual void OnCollisionLayerCreate(ujson::JsonNode _json);
    virtual void OnTerrainLayerCreate(ujson::JsonNode _json);
    virtual void OnBackgroundLayerCreate(ujson::JsonNode _json);
    virtual void OnCustomLayerCreate(ujson::JsonNode _json);
    virtual void OnGeometryLayerCreate(ujson::JsonNode _json);
    virtual void OnTilemapLayerCreate(ujson::JsonNode _json);
    bool ReadLevelFromFile(std::string _path);
    virtual bool Load();
    virtual void OnLoadFinished();
    virtual void Update();
    virtual void Draw(Camera* _camera);
};

#endif