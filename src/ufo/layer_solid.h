#ifndef LAYER_SOLID_H
#define LAYER_SOLID_H
#include "../../external/olcPixelGameEngine.h"
#include <string>
#include "layer.h"
#include <map>
#include <vector>

class Level;

class LayerSolid : public Layer{
public:
    std::string path;
    std::string visible;
    std::string decal;
    std::map<olc::vf2d, std::string> decals;
    std::vector<std::vector<std::string>> decal_layout; //add this to each class instead of using unnecessary inheritence
    LayerSolid() = default;
    LayerSolid(Level* _level ,std::string _name, std::string _type, std::string _path);
    //~LayerSolid();
    //virtual olc::Pixel GetPixel(olc::vf2d _position);
    void LoadLayer();
    void AcceptVisitor(CollisionBody* _collision_body);
    void Update();
    void Draw(Camera* _camera);
};

#endif