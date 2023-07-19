#ifndef LAYER_H
#define LAYER_H
#include "../../external/olcPixelGameEngine.h"
#include <string>
class Layer{
public:
    std::string name;
    std::string type;
    std::string visible;
    Layer() = default;
    Layer(std::string _name, std::string _type);
    ~Layer();
    virtual void LoadLayer();
    virtual void Update();
    virtual void Draw();
};

#endif