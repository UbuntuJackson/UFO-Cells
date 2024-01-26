#ifndef STACK_BASED_STATE_H
#define STACK_BASED_STATE_H

class StackBasedStateMachine;

class StackBasedState{
public:
    StackBasedStateMachine* state_machine;
    bool update_active;
    bool draw_active;
    StackBasedState();
    virtual void OnLoadFinished();
    virtual bool Load();
    virtual void Update();
    virtual void Draw();
};

#endif