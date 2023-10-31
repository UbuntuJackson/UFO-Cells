#ifndef CELL_ACTOR_H
#define CELL_ACTOR_H
#include "../../external/olcPixelGameEngine.h"
#include <string>
class Game;
class Camera;
class CellMap;
class LayerActor;

class CellActor{
public:
    Game *game;

    olc::vf2d position;
    olc::vf2d former_position;
    olc::vf2d velocity;
    olc::vf2d size;
    bool is_grounded;
    bool was_grounded;
    bool is_already_in_semi_solid = false;
    bool on_dynamic_solid = false;
    bool is_grounded_dynamic = false;
    bool was_grounded_dynamic = false;
    olc::vf2d correct_dynamic;
    int snap_to_ground;
    int snap_up_range;
    bool is_target = false;
    std::string mask;
    olc::Decal* mask_decal;
    std::string solid_layer;

    int draw_layer = 2;

    CellActor(olc::vf2d _position, Game *_game);
    CellActor(olc::vf2d _position, Game *_game, std::string _mask);
    virtual ~CellActor();
    bool IsOverlapping(CellMap* _map, olc::Decal *_decal, std::string _layer, olc::vf2d _position, olc::Pixel _colour = olc::WHITE);
    int IsOverlappingHeight(CellMap* _map, olc::Decal *_decal, std::string _layer, olc::vf2d _position, olc::Pixel _colour = olc::WHITE);
    int HeightUntilGround(CellMap* _map, olc::Decal *_decal, std::string _layer, olc::vf2d _position, olc::Pixel _colour = olc::WHITE);
    bool IsOverlappingOtherDecal(olc::Decal *_decal, olc::vf2d _position, olc::Decal *_other_decal, olc::vf2d _other_position, olc::Pixel _colour = olc::WHITE);

    virtual void AdjustCollisionX(CellMap* _map);
    virtual void AdjustCollisionY(CellMap* _map);
    virtual void AdjustDownSlope(CellMap* _map);
    virtual void AdjustUpSlope(CellMap* _map);
    virtual void AdjustEnteredDynamicSolidX(LayerActor* _act_layer);
    virtual void AdjustEnteredDynamicSolidY(LayerActor* _act_layer);
    virtual void AdjustEnterPseudoStaticSolidX(LayerActor* _act_layer);
    virtual void AdjustEnterPseudoStaticSolidY(LayerActor* _act_layer);
    virtual void AdjustEnterDynamicSolidX(LayerActor* _act_layer);
    virtual void AdjustEnterDynamicSolidY(LayerActor* _act_layer);
    virtual bool IsBeingEntered(olc::vf2d _position, olc::vf2d _delta_position, int _direction, std::string _mask);

    virtual void Update();
    virtual void Draw(Camera* _camera);
};

#endif