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
    bool was_updated = false;
    //std::string mask;
    int timelapse;
    DynamicSolid(int _id, olc::vf2d _position, Game* _game, std::string _mask, std::string _layer_tag);
    olc::vf2d GetVelocity();
    olc::vf2d GetPosition();
    void Update();
    void Draw(Camera* _camera);
};
#endif