#include "stack_based_state_machine.h"
#include "stack_based_state.h"
#include <memory>

void
StackBasedStateMachine::AddStateToTopOfStack(std::unique_ptr<StackBasedState> _state){

}

void
StackBasedStateMachine::ResetActiveStateInStack(){

}

void
StackBasedStateMachine::RemoveActiveStateInStack(){
    state_stack.pop_back();
}

void
StackBasedStateMachine::EmptyStack(){
    state_stack.clear();
}

void
StackBasedStateMachine::Update(){
    state_stack[state_stack.size()-1]->Update();
}