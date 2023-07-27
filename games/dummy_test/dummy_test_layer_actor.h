#ifndef DUMMY_TEST_LAYER_ACTOR_H
#define DUMMY_TEST_LAYER_ACTOR_H
#include "../../src/ufo/layer_actor.h"

class DummyTestLayerActor : public LayerActor{
public:
    DummyTestLayerActor(std::string _name, std::string _type);
    void LoadLayer();
};

#endif