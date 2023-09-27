#ifndef PLAYER_RAY_H
#define PLAYER_RAY_H
#include <vector>
#include "../../src/ufo/cell_actor.h"
#include "../../external/olcPixelGameEngine.h"
#include "game.h"
#include "mouse_control.h"

class PlayerRay{
    Game *game;
    Camera *camera;
    float radius;
    olc::vf2d start;
    olc::vf2d end;
    PlayerRay() = default;
    PlayerRay(Game* _game, Camera* _camera);
    virtual olc::vf2d GetTargetPosition();
    virtual void OnCollision();
    virtual olc::vf2d GetFirstCollision();
    virtual std::vector<olc::vf2d> GetAllCollisions();//En lista med coordinater ifall man vill manipulera samtliga object som man-                                               //interagerar med
    virtual CellActor* GetFirstActorDetected(); //För saker som inte är terräng, t.ex fiender
    virtual std::vector<CellActor*> GetAllActorsDetected(); //En lista med alla t.ex fiender man kommit i kontakt med
    virtual void Update();
    virtual void Draw(Camera* _camera);

};
#endif