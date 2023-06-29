#include "assets.h"
#include "olcPixelGameEngine.h"

Assets::Assets(){
    
}

Assets::~Assets(){
    DeleteAssets();
}

void
Assets::LoadAssets(){
    sprPin = new olc::Sprite("../res/masks/pin_pill.png");
    decPin = new olc::Decal(sprPin);
    sprMap = new olc::Sprite("../res/map.png");
    decMap = new olc::Decal(sprMap);
}

void
Assets::DeleteAssets(){
    delete sprPin;
    delete decPin;
    delete sprMap;
    delete decMap;
}