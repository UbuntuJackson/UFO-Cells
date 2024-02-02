#ifndef ASSETS_H
#define ASSETS_H
#include "../../external/olcPixelGameEngine.h"
#include "console.h"
#include <map>
#include <string>

class Assets{
public:
    //olc::Sprite* sprLoad;
    //olc::Decal *decLoad;

    std::map<std::string, olc::Decal*> decals;
    std::map<std::string, olc::Sprite*> sprites;

    Assets();
    ~Assets();
    void LoadDecal(const std::string& _path, const std::string& _name);
    olc::Decal* GetDecal(std::string _name);
    void LoadAssets();
    void DeleteAssets();
};

#endif
