#include "game.h"
#include "state.h"

Game::Game(State* _game_state) :
game_state{_game_state}
{}

Game::~Game(){
}

void Game::SetState(std::string _state, std::string _data){
    game_state = game_states[_state];
    game_state->Set(_data);
}