#ifndef STACK_BASED_STATE_MACHINE
#define STACK_BASED_STATE_MACHINE
#include <vector>
#include <memory>
#include "stack_based_state.h"

class StackBasedStateMachine{
public:
    //This stack could use some unique pointers
    std::vector<std::unique_ptr<StackBasedState>> state_stack;
    StackBasedStateMachine() = default;
    void AddStateToTopOfStack(std::unique_ptr<StackBasedState> _state);
    void ResetActiveStateInStack();
    void RemoveActiveStateInStack();
    void EmptyStack();
    void Update();
};

#endif