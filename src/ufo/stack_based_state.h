#ifndef STACK_BASED_STATE_H
#define STACK_BASED_STATE_H

class StackBasedStateMachine;

class StackBasedState{
    StackBasedStateMachine* stack_machine;
    bool update_active;
    bool draw_active;
    StackBasedState() = default;
    StackBasedState(StackBasedStateMachine* _state_machine);
    virtual void Update();
    virtual void Draw();
};

#endif