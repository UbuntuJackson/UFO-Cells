#ifndef GAME_STATE_H
#define GAME_STATE_H

class GameState{
    GameState();
    virtual void Request();
    virtual void Update();
    virtual void Draw();
};

#endif