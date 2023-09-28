#include "layer_terrain.h"
#include "layer.h"
#include "cellmap.h"
#include "camera.h"

LayerTerrain::LayerTerrain(CellMap* _map, std::string _name, std::string _type, std::string _path) : Layer(_map ,_name, _type), path{_path}{}

/*olc::Pixel
LayerTerrain::GetPixel(olc::vf2d _position){
    int chunk_x = std::floor(_position.x / game->CHUNK_SIZE.x);
    int chunk_y = std::floor(_position.y / game->CHUNK_SIZE.y);
    int pixel_x = int(std::floor(_position.x)) % int(game->CHUNK_SIZE.x);
    int pixel_y = int(std::floor(_position.y)) % int(game->CHUNK_SIZE.y);

    std::string dec = decal_layout[chunk_x][chunk_y];
    return game->asset_manager.GetDecal(dec)->sprite->GetPixel(olc::vf2d(pixel_x, pixel_y));
}*/

void
LayerTerrain::LoadLayer(){ //Pass it a map directly?
    olc::Sprite *spr = new olc::Sprite(path);
    map->map_sprites[name] = spr;
    map->map_size = spr->Size();

    olc::Decal *dec = new olc::Decal(spr);
    map->map_decals[name] = dec;
}

void
LayerTerrain::Update(){}

void
LayerTerrain::Draw(Camera* _camera){
    _camera->DrawDecal( //Give it camera instead of game?
            olc::vf2d(0.0f, 0.0f),
            map->map_decals[name]);
}