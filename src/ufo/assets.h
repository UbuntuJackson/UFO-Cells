#ifndef ASSETS_H
#define ASSETS_H
#include "../../external/olcPixelGameEngine.h"

class Assets{
public:
    olc::Sprite* sprPin;
    olc::Decal *decPin;
    olc::Sprite* sprMap;
    olc::Decal *decMap;
    Assets();
    ~Assets();
    void LoadAssets();
    void DeleteAssets();
};

#endif