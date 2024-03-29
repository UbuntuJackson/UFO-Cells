#ifndef ASSET_MANAGER_H
#define ASSET_MANAGER_H
#include "../../external/olcPixelGameEngine.h"
#include <string>
#include <map>
#include <memory>

class AssetManager{
public:
    AssetManager() = default;
    std::map<std::string, std::unique_ptr<olc::Sprite>> sprites;
    std::map<std::string,std::unique_ptr<olc::Decal>> decals;

    std::map<std::string, std::unique_ptr<olc::Sprite>>& GetSprites();
    void LoadSprite(const std::string& _path, const std::string& _name);
    olc::Sprite* GetSprite(std::string _name);
    std::map<std::string, std::unique_ptr<olc::Decal>>& GetDecals();
    void LoadDecal(const std::string& _path, const std::string& _name); //wouldn't this load both a sprite and a decal? And should the load functions return something?
    olc::Decal* GetDecal(std::string _name);
    void RemoveAsset(std::string _name);

    static AssetManager& Get(){static AssetManager self; return self;} //this practically makes AssetManager global.

};

#endif