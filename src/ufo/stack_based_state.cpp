#include "stack_based_state.h"
#include "stack_based_state_machine.h"

StackBasedState::StackBasedState() :
    update_active{true},
    draw_active{true}{}

bool StackBasedState::Load(){}
void StackBasedState::Update(){}
void StackBasedState::Draw(){}