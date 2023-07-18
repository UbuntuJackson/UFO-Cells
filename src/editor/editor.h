#ifndef EDITOR_H
#define EDITOR_H
#include "../ufo/layer.h"
#include <vector>
class Editor{
public:
    std::vector<Layer*> layers;
    Editor() = default;
    Editor();
    ~Editor();
    void Update();
};

#endif