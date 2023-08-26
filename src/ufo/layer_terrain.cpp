#include "layer_terrain.h"
#include "../program/ufo_global.h"
#include "layer.h"

LayerTerrain::LayerTerrain(std::string _name, std::string _type, std::string _path) : Layer(_name, _type), path{_path}{}

olc::Pixel
LayerTerrain::GetPixel(olc::vf2d _position){
    int chunk_x = std::floor(_position.x / UfoGlobal::game->CHUNK_SIZE.x);
    int chunk_y = std::floor(_position.y / UfoGlobal::game->CHUNK_SIZE.y);
    int pixel_x = int(std::floor(_position.x)) % int(UfoGlobal::game->CHUNK_SIZE.x);
    int pixel_y = int(std::floor(_position.y)) % int(UfoGlobal::game->CHUNK_SIZE.y);

    std::string dec = decal_layout[chunk_x][chunk_y];
    return UfoGlobal::game->asset_manager.GetDecal(dec)->sprite->GetPixel(olc::vf2d(pixel_x, pixel_y));
}

void
LayerTerrain::LoadLayer(){
    olc::Sprite *spr = new olc::Sprite(path);
    UfoGlobal::game->cell_map.map_sprites[name] = spr;
    UfoGlobal::game->cell_map.map_size = spr->Size();

    olc::Decal *dec = new olc::Decal(spr);
    UfoGlobal::game->cell_map.map_decals[name] = dec;
}

void
LayerTerrain::Update(){}

void
LayerTerrain::Draw(){
    UfoGlobal::game->camera.DrawDecal(
            olc::vf2d(0.0f, 0.0f),
            UfoGlobal::game->cell_map.map_decals[name]);
}