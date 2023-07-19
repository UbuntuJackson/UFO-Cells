#ifndef LAYER_TERRAIN_H
#define LAYER_TERRAIN_H
#include "../../external/olcPixelGameEngine.h"
#include <string>
#include "layer.h"

class LayerTerrain : public Layer{
public:
    std::string path;
    std::string visible;
    std::string decal;
    LayerTerrain() = default;
    LayerTerrain(std::string _name, std::string _type, std::string _path);
    //~LayerTerrain();
    void LoadLayer();
    void Update();
    void Draw();
};

#endif