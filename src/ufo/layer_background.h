#ifndef LAYER_BACKGROUND_H
#define LAYER_BACKGROUND_H
#include "layer.h"
#include "../../external/olcPixelGameEngine.h"
#include <string>

class LayerBackground : public Layer{
public:
    olc::vf2d parallax;
    std::string decal;
    LayerBackground() = default;
    LayerBackground(std::string _decal);
    ~LayerBackground();
    void Draw();
};

#endif