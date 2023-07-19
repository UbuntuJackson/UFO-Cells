#include "layer_background.h"
#include "../program/ufo_global.h"
#include "layer.h"

LayerBackground::LayerBackground(std::string _name, std::string _type, std::string _path) : Layer(_name, _type), path{_path}{}

void
LayerBackground::LoadLayer(){
    olc::Sprite *spr = new olc::Sprite(path);
    UfoGlobal::program.cell_map.map_sprites[name] = spr;
    UfoGlobal::program.cell_map.map_size = spr->Size();

    olc::Decal *dec = new olc::Decal(spr);
    UfoGlobal::program.cell_map.map_decals[name] = dec;
}

void
LayerBackground::Update(){}

void
LayerBackground::Draw(){
    UfoGlobal::program.camera.DrawDecal(
            olc::vf2d(0.0f, 0.0f),
            UfoGlobal::program.cell_map.map_decals[name]);
}