#ifndef LEVEL_LOADER_H
#define LEVEL_LOADER_H
#include <string>
class Game;
class StatePlay;
class LevelLoader{
    Game* game;
    StatePlay* level_to_load;
    LevelLoader() = default;
    LevelLoader(Game* _game);
    bool Set(std::string _path);
    void Update();
};

#endif