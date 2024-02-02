#include "assets.h"

Assets::Assets(){}

Assets::~Assets(){
    DeleteAssets();
}

void Assets::LoadDecal(const std::string& _path, const std::string& _name) {
    olc::Sprite* spr = new olc::Sprite();

    switch (spr->LoadFromFile(_path)){
        case olc::rcode::NO_FILE:
            Console::Out("Error: The file does not exist at path", _path);
            break;
        case olc::rcode::FAIL:
            Console::Out("Error: Failed to load the file at path", _path);
            break;
        default:
            break;
    }

    olc::Decal* dec = new olc::Decal(spr);

    sprites[_name] = spr;
    decals[_name] = dec;
}

olc::Decal*
Assets::GetDecal(std::string _name) {
    return decals.at(_name);
}

void Assets::LoadAssets(){}

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