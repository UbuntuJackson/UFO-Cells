#include "level_loader.h"
#include <string>
#include "game.h"
#include "level.h"
#include "console.h"

LevelLoader::LevelLoader(StackBasedStateMachine* _state_machine ,Level* _level) :
    StackBasedState(){}

void
LevelLoader::Update(){
    Console::Out("loading...");
}