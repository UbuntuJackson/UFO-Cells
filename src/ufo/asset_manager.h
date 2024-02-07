#ifndef ASSET_MANAGER_H
#define ASSET_MANAGER_H
#include "../../external/olcPixelGameEngine.h"
#include <string>
#include <map>
#include <memory>

class AssetManager{
public:
    std::map<std::string, std::unique_ptr<olc::Sprite>> sprites;
    std::map<std::string,std::unique_ptr<olc::Decal>> decals;

    void LoadSprite(const std::string& _path, const std::string& _name);
    olc::Sprite* GetSprite(std::string _name);
    void RemoveSprite(std::string _name);
    void LoadDecal(const std::string& _path, const std::string& _name); //wouldn't this load both a sprite and a decal? And should the load functions return something?
    olc::Decal* GetDecal(std::string _name);
    void RemoveDecal(std::string _name);

    static AssetManager& GetSelf(){static AssetManager self; return self;} //this practically makes AssetManager global.

};

#endif