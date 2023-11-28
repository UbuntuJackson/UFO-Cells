#include "stack_based_state_machine.h"
#include "stack_based_state.h"

void
StackBasedStateMachine::AddStateToTopOfStack(StackBasedState* _state){

}

void
StackBasedStateMachine::ResetActiveStateInStack(){

}

void
StackBasedStateMachine::RemoveActiveStateInStack(){
    delete state_stack[state_stack.size()-1];
    state_stack.pop_back();
}

void
StackBasedStateMachine::EmptyStack(){
    for(auto state : state_stack){
        delete state;
    }
    state_stack.clear();
}

void
StackBasedStateMachine::Update(){
    /*for(auto state : state_stack){
        if(state->update_active){
            state->Update();
        }
        if(state->draw_active){
            state->Draw();
        }
    }*/
    state_stack[state_stack.size()-1]->Update();
}