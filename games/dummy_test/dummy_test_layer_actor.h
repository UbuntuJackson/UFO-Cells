#ifndef DUMMY_TEST_LAYER_ACTOR_H
#define DUMMY_TEST_LAYER_ACTOR_H
#include "../../src/ufo/layer_actor.h"
#include "dummy_test_game.h"
class Camera;
class DummyTestLayerActor : public LayerActor{
public:
    DummyTestGame* game;
    DummyTestLayerActor() = default;
    DummyTestLayerActor(DummyTestGame* _game, CellMap* _map ,std::string _name, std::string _type);
    void LoadLayer();
    void Draw(Camera* _camera);
};

#endif