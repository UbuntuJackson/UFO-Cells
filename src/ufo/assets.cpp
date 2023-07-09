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
    olc::Decal *dec = new olc::Decal(spr);
    decals[_name] = dec;
}

void
Assets::LoadAssets(){
    //sprLoadingScreen = new olc::Sprite("../res/masks/pill_small.png");
    //decLoadingScreen = new olc::Decal(sprLoadingScreen);
    sprPin = new olc::Sprite("../res/masks/pill_small.png");
    decPin = new olc::Decal(sprPin);
    sprMap = new olc::Sprite("../res/map.png");
    decMap = new olc::Decal(sprMap);
    sprLoad = new olc::Sprite("../res/loading_screen/loading_screen.png");
    decLoad = new olc::Decal(sprLoad);
}

void
Assets::DeleteAssets(){
    delete sprPin;
    delete decPin;
    delete sprMap;
    delete decMap;

    for(auto &[a, i] : decals){
        delete i;
    }
}