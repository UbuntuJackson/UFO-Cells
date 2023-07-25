#include "layer.h"
#include "layer_solid.h"
#include "../program/ufo_global.h"
#include <cmath>
#include <string>
#include "../program/ufo_global.h"

//maybe put strings in layer vector instead that refers to keys in a map with <string, Layer>

LayerSolid::LayerSolid(std::string _name, std::string _type, std::string _path) : Layer(_name, _type), path{_path}{}

olc::Pixel
LayerSolid::GetPixel(olc::vf2d _position){
    int chunk_x = std::floor(_position.x / UfoGlobal::program.game->CHUNK_SIZE.x);
    int chunk_y = std::floor(_position.y / UfoGlobal::program.game->CHUNK_SIZE.y);
    int pixel_x = int(std::floor(_position.x)) % int(UfoGlobal::program.game->CHUNK_SIZE.x);
    int pixel_y = int(std::floor(_position.y)) % int(UfoGlobal::program.game->CHUNK_SIZE.y);

    std::string dec = decal_layout[chunk_x][chunk_y];
    return UfoGlobal::program.asset_manager.GetDecal(dec)->sprite->GetPixel(olc::vf2d(pixel_x, pixel_y));
}

void
LayerSolid::LoadLayer(){
    olc::Sprite *spr = new olc::Sprite(path);
    UfoGlobal::program.cell_map.map_sprites[name] = spr;
    UfoGlobal::program.cell_map.map_size = spr->Size();

    olc::Decal *dec = new olc::Decal(spr);
    UfoGlobal::program.cell_map.map_decals[name] = dec;
}

void
LayerSolid::Update(){}

void
LayerSolid::Draw(){
    //UfoGlobal::program.camera.DrawDecal(
    //        olc::vf2d(0.0f, 0.0f),
    //        UfoGlobal::program.cell_map.map_decals[name]);
}