#include "layer_solid.h"
#include "../program/ufo_global.h"

LayerSolid::LayerSolid() : Layer(){}

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
    UfoGlobal::program.camera.DrawDecal(
            olc::vf2d(0.0f, 0.0f),
            UfoGlobal::program.cell_map.map_decals[name]);
}