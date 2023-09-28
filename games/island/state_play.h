#ifndef STATE_PLAY_H
#define STATE_PLAY_H

class Island;

class StatePlay{
    Island *game;
    StatePlay(Island* _game);
    void Set();
    void Update();
};

#endif