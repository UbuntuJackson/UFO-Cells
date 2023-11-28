#ifndef LEVEL_LOADER_H
#define LEVEL_LOADER_H
#include <string>
#include "stack_based_state.h"
#include "stack_based_state_machine.h"

class Level;

class StatePlay;
class LevelLoader : public StackBasedState{
    Level* _level;
    LevelLoader() = default;
    LevelLoader(StackBasedStateMachine* _state_machine ,Level* _level);
    void Update();
};

#endif