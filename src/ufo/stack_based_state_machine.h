#ifndef STACK_BASED_STATE_MACHINE
#define STACK_BASED_STATE_MACHINE
#include <vector>
#include "stack_based_state.h"

class StackBasedStateMachine{
    std::vector<StackBasedStack> state_stack;
    StackBasedStateMachine() = default;
    void AddStateToTopOfStack(StackBasedState* _state);
    void ResetActiveStateInStack();
    void RemoveActiveStateInStack();
    void EmptyStack();
    void Update();
};

#endif