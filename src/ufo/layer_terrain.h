#ifndef LAYER_TERRAIN_H
#define LAYER_TERRAIN_H
#include "../../external/olcPixelGameEngine.h"
#include <string>
class LayerTerrain{
public:
    std::string visible;
    std::string decal;
    LayerTerrain() = default;
    LayerTerrain(std::string _decal);
    ~LayerTerrain();
    void Update();
    void Draw();
};

#endif