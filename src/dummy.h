#ifndef DUMMY_H
#define DUMMY_H

#include "cell_actor.h"

class Dummy : public CellActor{
public:
    int i = 0;
    Dummy(Program *_program,olc::vf2d _position);
    void Update();
    void Draw();

};

#endif