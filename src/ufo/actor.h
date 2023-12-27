#ifndef ACTOR_H
#define ACTOR_H
#include <string>
#include "../../external/olcPixelGameEngine.h"
class Camera;
class Actor{
    int id;
    std::string layer_tag;
    olc::vf2d position;
    Actor(int _id, olc::vf2d _position, std::string _layer_tag);
    void Update();
    void Draw(Camera* _camera);
    int GetID();
    std::string GetType();
};

#endif