#ifndef LAYER_H
#define LAYER_H
#include "../../external/olcPixelGameEngine.h"
#include <string>

class Game;
class CellMap;
class Camera;

class Layer{
public:
    //Game* game; //Have CellMap* map instead of game
    CellMap* map;

    std::string name;
    std::string type;
    std::string visible;
    Layer() = default;
    Layer(CellMap* _map,std::string _name, std::string _type);
    virtual ~Layer();
    virtual void LoadLayer();
    virtual void Update();
    virtual void Draw(Camera* _camera);
};

#endif