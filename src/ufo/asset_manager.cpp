#include "../../external/olcPixelGameEngine.h"
#include <memory>
#include "asset_manager.h"
#include "console.h"
#include <map>

std::map<std::string, std::unique_ptr<olc::Sprite>> AssetManager::GetSprites(){
    return sprites;
}

void AssetManager::LoadSprite(const std::string& _path, const std::string& _name) {
    olc::Sprite* spr = new olc::Sprite(_path);

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

    sprites[_name] = std::unique_ptr<olc::Sprite>(spr);
}

olc::Sprite*
AssetManager::GetSprite(std::string _name) {
    if(!sprites.count(_name)) Console::Out("Error: No entry with given key.");
    return sprites.at(_name).get();
}

void
AssetManager::RemoveSprite(std::string _name){
    if(!sprites.erase(_name)) Console::Out("Error: Sprite with given key does not exist.");
}

void AssetManager::LoadDecal(const std::string& _path, const std::string& _name) {
    olc::Sprite* spr = new olc::Sprite(_path);

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

    sprites[_name] = std::unique_ptr<olc::Sprite>(spr);
    decals[_name] = std::unique_ptr<olc::Decal>(dec);
}

olc::Decal*
AssetManager::GetDecal(std::string _name) {
    if(!decals.count(_name)) Console::Out("Error: No entry with given key.");
    return decals.at(_name).get();
}

void
AssetManager::RemoveDecal(std::string _name){
    if(!sprites.erase(_name)) Console::Out("Error: Sprite with given key does not exist.");
    if(!decals.erase(_name)) Console::Out("Error: Sprite with given key does not exist.");
}