#include "stack_based_state.h"
#include "stack_based_state_machine.h"

StackBasedState::StackBasedState(StackBasedStateMachine* _state_machine) : stack_machine{_state_machine}

void StackBasedState::Update(){}
void StackBasedState::Draw(){}