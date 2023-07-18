#ifndef LAYER_H
#define LAYER_H
#include "../../external/olcPixelGameEngine.h"
#include <string>
class Layer{
public:
    std::string name;
    std::string visible;
    Layer();
    ~Layer();
    virtual void Update();
    virtual void Draw();
};

#endif