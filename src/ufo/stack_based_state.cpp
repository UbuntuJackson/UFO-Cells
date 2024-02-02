#include "stack_based_state.h"
#include "stack_based_state_machine.h"

StackBasedState::StackBasedState() :
    update_active{true},
    draw_active{true}{}


void StackBasedState::OnLoadFinished(){}
bool StackBasedState::Load(){return false;}
void StackBasedState::Update(){}
void StackBasedState::Draw(){}
