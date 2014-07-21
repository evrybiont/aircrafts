#ifndef STATE_H
#define STATE_H

#include "tools.h"

class State {
  protected:
    bool is_active;
    enum scope { INTRO, MENU, LEVELS };
    class Game *game;

  public:
    State();
    virtual void init(class Game*) = 0;
    virtual int nextArea() = 0;
    virtual void setGame(Game*) = 0;
};

#endif
