#include "layer_background.h"
#include "layer.h"
#include "level.h"
#include "camera.h"
#include <string>
#include <iostream>

LayerBackground::LayerBackground(Level* _level ,std::string _name, std::string _type, std::string _path) : Layer(_level ,_name, _type), path{_path}{}

/*olc::Pixel
LayerBackground::GetPixel(olc::vf2d _position){
    int chunk_x = std::floor(_position.x / UfoGlobal::game->CHUNK_SIZE.x);
    int chunk_y = std::floor(_position.y / UfoGlobal::game->CHUNK_SIZE.y);
    int pixel_x = int(std::floor(_position.x)) % int(UfoGlobal::game->CHUNK_SIZE.x);
    int pixel_y = int(std::floor(_position.y)) % int(UfoGlobal::game->CHUNK_SIZE.y);

    std::string dec = decal_layout[chunk_x][chunk_y];
    return UfoGlobal::game->asset_manager.GetDecal(dec)->sprite->GetPixel(olc::vf2d(pixel_x, pixel_y));
}*/

void
LayerBackground::LoadLayer(){
    std::cout << path << std::endl;
    olc::Sprite *spr = new olc::Sprite(path);
    level->level_sprites[name] = spr;
    level->map_size = spr->Size();
    std::cout << "loading decal now..." << std::endl;
    olc::Decal *dec = new olc::Decal(spr);
    level->level_decals[name] = dec;
}

void
LayerBackground::Update(){}

void
LayerBackground::Draw(Camera* _camera){
    _camera->DrawDecal(
            olc::vf2d(0.0f, 0.0f),
            level->level_decals[name]);
}