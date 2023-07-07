#include "game.h"
#include "state.h"

Game::Game(State* _game_state) :
game_state{_game_state}
{}

Game::~Game(){
    delete game_state;
}