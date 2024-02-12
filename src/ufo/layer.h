#ifndef LAYER_H
#define LAYER_H
#include "../../external/olcPixelGameEngine.h"
#include <string>
class Actor;
class Game;
class Level;
class Camera;

class Layer{
public:
    //Game* game; //Have CellMap* map instead of game
    Level* level;

    std::string name;
    std::string type;
    std::string visible;
    Layer() = default;
    Layer(Level* _level,std::string _name, std::string _type);
    virtual ~Layer();
    virtual void LoadLayer();
    virtual void ProcessActors();
    virtual void AcceptVisitor(Actor* _actor);
    virtual void Update();
    virtual void Draw(Camera* _camera);
};

#endif