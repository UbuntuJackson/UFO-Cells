#ifndef DYNAMIC_SOLID_H
#define DYNAMIC_SOLID_H
#include "cell_actor.h"
#include <string>
#include "../../external/olcPixelGameEngine.h"
class Camera;
class Game;

class DynamicSolid : public CellActor{
public:
    float angle = 0;
    //std::string mask;
    int timelapse;
    DynamicSolid(olc::vf2d _position, Game* _game, std::string _mask);
    olc::vf2d GetMovement();
    void Update();
    void Draw(Camera* _camera);
};
#endif