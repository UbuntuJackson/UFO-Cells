#ifndef LAYER_BACKGROUND_H
#define LAYER_BACKGROUND_H
#include "layer.h"
#include "../../external/olcPixelGameEngine.h"
#include <string>

class LayerBackground : public Layer{
public:
    olc::vf2d parallax;
    std::string path;
    std::string decal;
    LayerBackground() = default;
    LayerBackground(std::string _name, std::string _type, std::string _path);
    //~LayerBackground();
    void LoadLayer();
    void Update();
    void Draw();
};

#endif