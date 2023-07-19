#include "layer_terrain.h"
#include "../program/ufo_global.h"

LayerTerrain::LayerTerrain(std::string _name, std::string _type, std::string _path) : Layer(_name, _type), path{_path}{}

void
LayerTerrain::LoadLayer(){
    olc::Sprite *spr = new olc::Sprite(path);
    UfoGlobal::program.cell_map.map_sprites[name] = spr;
    UfoGlobal::program.cell_map.map_size = spr->Size();

    olc::Decal *dec = new olc::Decal(spr);
    UfoGlobal::program.cell_map.map_decals[name] = dec;
}

void
LayerTerrain::Update(){}

void
LayerTerrain::Draw(){
    UfoGlobal::program.camera.DrawDecal(
            olc::vf2d(0.0f, 0.0f),
            UfoGlobal::program.cell_map.map_decals[name]);
}