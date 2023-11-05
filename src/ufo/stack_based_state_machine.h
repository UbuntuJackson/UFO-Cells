#ifndef STACK_BASED_STATE_MACHINE
#define STACK_BASED_STATE_MACHINE
#include <vector>

class State;
class StackBasedStateMachine{
    std::vector<State*> state_stack;
    StackBasedStateMachine() = default;
    void AddStateToTopOfStack(State* _state);
    void ResetActiveStateInStack();
    void RemoveActiveStateInStack();
    void EmptyStack();
};

#endif