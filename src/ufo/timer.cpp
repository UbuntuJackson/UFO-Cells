#include "timer.h"
#include "game.h"

Timer::Timer(Game* _game) :
game{_game},
period_in_seconds{0.0f}
{

}

void
Timer::Start(float _period){
    time_start_in_seconds = game->game_time;
    time_end_in_seconds = time_start_in_seconds + period_in_seconds;
}

float
Timer::GetTimeleft(){
    return time_end_in_seconds - game->game_time;
}

float
Timer::GetTimeSinceStart(){
    return game->game_time - time_start_in_seconds;
}

bool
Timer::TimeOut(){
    if(game->game_time >= time_end_in_seconds){
        return true;
    }
    return false;
}