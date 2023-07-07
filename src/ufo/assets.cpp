#include "assets.h"
#include "../../external/olcPixelGameEngine.h"

Assets::Assets(){

}

Assets::~Assets(){
    DeleteAssets();
}

void
Assets::LoadAssets(){
    //sprLoadingScreen = new olc::Sprite("../res/masks/pill_small.png");
    //decLoadingScreen = new olc::Decal(sprLoadingScreen);
    sprPin = new olc::Sprite("../res/masks/pill_small.png");
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