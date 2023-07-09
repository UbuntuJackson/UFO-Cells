#ifndef ASSETS_H
#define ASSETS_H
#include "../../external/olcPixelGameEngine.h"

class Assets{
public:
    //olc::Sprite* sprLoadingScreen;
    //olc::Decal *decLoadingScreen;
    olc::Sprite* sprPin;
    olc::Decal *decPin;
    olc::Sprite* sprMap;
    olc::Decal *decMap;
    olc::Sprite* sprLoad;
    olc::Decal *decLoad;
    Assets();
    ~Assets();
    void LoadAssets();
    void DeleteAssets();
};

#endif