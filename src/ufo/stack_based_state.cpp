#include "stack_based_state.h"
#include "stack_based_state_machine.h"

StackBasedState::StackBasedState(StackBasedStateMachine* _state_machine) :
    state_machine{_state_machine},
    update_active{true},
    draw_active{true}{}

void StackBasedState::Update(){}
void StackBasedState::Draw(){}