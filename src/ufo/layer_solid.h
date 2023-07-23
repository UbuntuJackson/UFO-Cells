#ifndef LAYER_SOLID_H
#define LAYER_SOLID_H
#include "../../external/olcPixelGameEngine.h"
#include <string>
#include "layer.h"
#include <map>
#include <vector>

class LayerSolid : public Layer{
public:
    std::string path;
    std::string visible;
    std::string decal;
    std::map<olc::vf2d, std::string> decals;
    std::vector<std::vector<std::string>> decal_layout;
    LayerSolid() = default;
    LayerSolid(std::string _name, std::string _type, std::string _path);
    //~LayerSolid();
    virtual olc::Pixel GetPixel(olc::vf2d _position);
    void LoadLayer();
    void Update();
    void Draw();
};

#endif