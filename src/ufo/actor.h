#ifndef ACTOR_H
#define ACTOR_H
#include <string>
#include "../../external/olcPixelGameEngine.h"
#include <vector>
class Camera;
class Actor{
public:
    std::vector<Actor> attachments;
    int id;
    std::string layer_tag;
    olc::vf2d position;
    Actor(int _id, olc::vf2d _position, std::string _layer_tag);
    virtual void Update();
    virtual void Draw(Camera* _camera);
    virtual void Draw();
    int GetID();
    std::string GetType();
};

#endif