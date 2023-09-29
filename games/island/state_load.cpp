#include "state_load.h"
#include "island.h"
#include "../../src/ufo/state.h"
#include "../../src/ufo/cellmap.h"

StateLoad::StateLoad(Island* _game,CellMap* _map, TypeRegistry *_registry): UfoLoad(_game,_map, _registry), game{_game}{}
void
StateLoad::OnLoadFinished(){
    game->game_state = &(game->play);
    game->play.Set();
}