#ifndef LAYER_SOLID_H
#define LAYER_SOLID_H
#include "../../external/olcPixelGameEngine.h"
#include <string>
class LayerSolid{
public:
    std::string visible;
    std::string decal;
    LayerSolid() = default;
    LayerSolid(std::string _decal);
    ~LayerSolid();
    void Update();
    void Draw();
};

#endif