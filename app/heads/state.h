#ifndef STATE_H
#define STATE_H

#include "tools.h"

class State {
  protected:
    bool is_active;
    class Game *game;

  public:
    State();
    virtual ~State();
    virtual void init(class Game*) = 0;
    virtual void setGame(Game*) = 0;
};

#endif
