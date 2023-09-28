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
    std::vector<std::vector<std::string>> decal_layout;
    LayerBackground() = default;
    LayerBackground(CellMap* _map ,std::string _name, std::string _type, std::string _path);
    //~LayerBackground();
    //virtual olc::Pixel GetPixel(olc::vf2d _position);
    void LoadLayer();
    void Update();
    void Draw(Camera* _camera);
};

#endif