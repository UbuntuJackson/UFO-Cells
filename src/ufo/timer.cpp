#include "timer.h"

Timer::Timer()
: is_ticking{false},
time_in_frames{0}
{

}

void
Timer::Start(){
    is_ticking = true;
}

void
Timer::Stop(){
    is_ticking = false;
}

void
Timer::Reset(){
    Start();
    time_in_frames = 0;
}

bool
Timer::Check(){
    time_in_frames++;
    if(time_in_frames <= 0){
        Stop();
        return false;
    }
    return true;
}