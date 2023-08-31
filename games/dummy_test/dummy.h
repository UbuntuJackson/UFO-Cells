#ifndef DUMMY_H
#define DUMMY_H
#include "../../src/ufo/camera.h"
#include "../../src/ufo/cell_actor.h"
#include "dummy_test_layer_actor.h"
#include "dummy_test_game.h"

#include <string>

class Camera;

class Dummy : public CellActor{
public:
    DummyTestGame* game;

    bool on_dynamic_solid;
    std::string solid_layer = "solid";
    bool is_already_in_semi_solid = false;
    olc::vf2d former_position;
    std::string mask;
    olc::Decal* mask_decal;

    olc::vf2d dynamic_ride_velocity = {0.0f, 0.0f};
    bool entered_horisontally_dynamic = false;

    int input_frame;
    bool play_input;
    struct KeyInput{
        bool left_held;
        bool right_held;
        bool z_pressed;
    };

    std::vector<KeyInput> player_input_recorded;
    std::vector<KeyInput> player_input_play;
    Dummy(olc::vf2d _position, DummyTestGame* _game);
    ~Dummy();
    void Update();
    void Draw(Camera* _camera);
    void AdjustCollisionX();
    void AdjustCollisionY();
    void AdjustDownSlope();
    void AdjustUpSlope();
    void OnDynamicSolid(DummyTestLayerActor* _act_layer);
    void AdjustEnteredDynamicSolidX(DummyTestLayerActor* _act_layer);
    void AdjustEnteredDynamicSolidY(DummyTestLayerActor* _act_layer);
    void AdjustEnterPseudoStaticSolidX(DummyTestLayerActor* _act_layer);
    void AdjustEnterPseudoStaticSolidY(DummyTestLayerActor* _act_layer);
    void AdjustEnterDynamicSolidX(DummyTestLayerActor* _act_layer);
    void AdjustEnterDynamicSolidY(DummyTestLayerActor* _act_layer);
    void WriteInputJson();
    void ParseInputJson();
};

#endif