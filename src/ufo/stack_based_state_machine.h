#ifndef STACK_BASED_STATE_MACHINE
#define STACK_BASED_STATE_MACHINE
#include <vector>

class StackBasedState;

class StackBasedStateMachine{
public:
    //This stack could use some unique pointers
    std::vector<StackBasedState*> state_stack;
    StackBasedStateMachine() = default;
    void AddStateToTopOfStack(StackBasedState* _state);
    void ResetActiveStateInStack();
    void RemoveActiveStateInStack();
    void EmptyStack();
    void Update();
};

#endif