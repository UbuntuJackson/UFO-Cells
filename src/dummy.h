#ifndef DUMMY_H
#define DUMMY_H

#include "cell_actor.h"

class Dummy : public CellActor{
public:
    Dummy(Program *_program,olc::vf2d _position);
    virtual void Update();
    virtual void Draw();

};

#endif