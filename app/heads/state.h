#ifndef STATE_H
#define STATE_H

#include "../lib/sdl.h"

class State {
  protected:
    bool is_active;
    enum scope { INTRO, MENU, LEVELS };
  public:
    State();
    virtual void init(class Game*) = 0;
    virtual int nextArea() = 0;
};

#endif
