#include "level_loader.h"
#include <string>
#include "game.h"
#include "level.h"

LevelLoader::LevelLoader(StackBasedStateMachine* _state_machine ,Level* _level) :
    StackBasedState(_state_machine),
    level{_level}{}

void
LevelLoader::Update(){
    std::cout << "is this running" << std::endl;
    if(!level->Load()) //Load can draw the image instead
    {
        level->OnLoadFinished();
        state_machine->RemoveActiveStateInStack();
    }
}