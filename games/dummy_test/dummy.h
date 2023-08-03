#ifndef DUMMY_H
#define DUMMY_H
#include "../../src/ufo/camera.h"
#include "../../src/ufo/cell_actor.h"
#include <string>
class Dummy : public CellActor{
public:
    int i = 0;
    std::string solid_layer = "solid";
    bool is_already_in_semi_solid = false;
    olc::vf2d former_position;
    std::string mask;
    olc::Decal* mask_decal;

    olc::vf2d dynamic_ride_offset = {0.0f, 0.0f};

    bool record_input;
    int input_frame;
    bool play_input;
    struct KeyInput{
        bool left_held;
        bool right_held;
        bool z_pressed;
    };

    std::vector<KeyInput> player_input_recorded;
    std::vector<KeyInput> player_input_play;
    Dummy(olc::vf2d _position);
    ~Dummy();
    void Update();
    void Draw();
    void AdjustCollisionX();
    void AdjustCollisionY();
    void AdjustDownSlope();
    void AdjustUpSlope();

    void WriteInputJson();
    void ParseInputJson();
};

#endif