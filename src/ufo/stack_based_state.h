#ifndef STACK_BASED_STATE_H
#define STACK_BASED_STATE_H

#include <ufo/fundamental.h>

class StackBasedStateMachine;

class StackBasedState : public Fundamental{
public:
    StackBasedStateMachine* state_machine;
    bool update_active;
    bool draw_active;
    StackBasedState();
    virtual void OnLoadFinished() = 0;
    virtual bool Load() = 0;
    virtual void Update() = 0;
    virtual void Draw() = 0;
};

#endif