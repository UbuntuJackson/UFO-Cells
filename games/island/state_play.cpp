#include "state_play.h"
#include "island.h"

StatePlay::StatePlay(Island *_game) : game{_game}{}

void
StatePlay::Set(){

}

void
StatePlay::Update(){
    for(auto layer : game->map.layers){
        layer -> Update();
    }
    game->map.Draw(&(game->camera));
}