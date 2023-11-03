#include "level_loader.h"
#include <string>
LevelLoader::Set(std::string _path){
    game->level = new Level(_path)
}
LevelLoader::Update(){
    if(game->level.load())
    {
      //DrawLoadingScreenImage();
    }
    else{
      game->active_state_ptr = &(game->state_play)
    }
}