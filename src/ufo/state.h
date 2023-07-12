#ifndef STATE_H
#define STATE_H
#include <string>
#include "state.h"

class State{
public:
    State();
    ~State();
    virtual void SetPlay(std::string _map);
    virtual void SetLoad(std::string _map);
    virtual void SetMenu(std::string _menu);
    virtual void Update();
    virtual void Set(std::string _data);
    virtual std::string GetData();
};

#endif