#ifndef LEVEL_LOADER_H
#define LEVEL_LOADER_H
#include <string>
#include "stack_based_state.h"
#include "stack_based_state_machine.h"

class Level;

class LevelLoader : public StackBasedState{
public:
    Level* level;
    StackBasedStateMachine* state_machine;
    LevelLoader() = default;
    LevelLoader(StackBasedStateMachine* _state_machine ,Level* _level);
    void Update();
};

#endif