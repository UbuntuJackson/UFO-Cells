#ifndef TIMER_H
#define TIMER_H

class Timer{
public:
    int time_in_frames;
    bool is_ticking;
    void Start();
    void Stop();
    void Reset();
    bool Check();    
};

#endif