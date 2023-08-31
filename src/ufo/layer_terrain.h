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
    std::vector<std::vector<std::string>> decal_layout;
    LayerTerrain() = default;
    LayerTerrain(Camera* _camera, CellMap* _map, std::string _name, std::string _type, std::string _path);
    //~LayerTerrain();
    //virtual olc::Pixel GetPixel(olc::vf2d _position);
    void LoadLayer();
    void Update();
    void Draw(Camera* _camera);
};

#endif