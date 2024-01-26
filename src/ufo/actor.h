#ifndef ACTOR_H
#define ACTOR_H
#include <string>
#include "../../external/olcPixelGameEngine.h"
#include <vector>
#include <functional>
#include <iostream>

class Camera;
class Actor{
public:
    std::function<void(int)> remove_pointer_from_container = [](int){std::cout << "Destruct function empty.";};
    std::vector<Actor> attachments;
    int id;
    std::string layer_tag;
    olc::vf2d position;
    Actor(int _id, olc::vf2d _position, std::string _layer_tag);
    Actor(int _id, olc::vf2d _position, std::string _layer_tag, std::function<void(int)> *_destruct_instance);
    virtual void Update();
    virtual void Draw(Camera* _camera);
    virtual void Draw();
    int GetID();
    void OnRemoval();
    virtual std::string GetType();
};

#endif