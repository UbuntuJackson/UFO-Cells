#ifndef LAYER_SOLID_H
#define LAYER_SOLID_H
#include "../../external/olcPixelGameEngine.h"
#include <string>
#include "layer.h"

class LayerSolid : public Layer{
public:
    std::string path;
    std::string visible;
    std::string decal;
    LayerSolid() = default;
    LayerSolid(std::string _name, std::string _type, std::string _path);
    //~LayerSolid();
    void LoadLayer();
    void Update();
    void Draw();
};

#endif