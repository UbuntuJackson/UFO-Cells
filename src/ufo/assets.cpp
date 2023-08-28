#include "assets.h"
#include "../../external/olcPixelGameEngine.h"
#include <string>

Assets::Assets(){

}

Assets::~Assets(){
    DeleteAssets();
}

void
Assets::LoadDecal(std::string _path, std::string _name){
    olc::Sprite *spr = new olc::Sprite(_path);
    sprites[_name] = spr;
    olc::Decal *dec = new olc::Decal(spr);
    decals[_name] = dec;
}

olc::Decal*
Assets::GetDecal(std::string _name){
    return decals[_name];
}

void
Assets::LoadAssets(){
}

void
Assets::DeleteAssets(){
    //delete sprLoad;
    //delete decLoad;
    for(auto &[a, i] : sprites){
        delete i;
    }
    for(auto &[a, i] : decals){
        delete i;
    }
}