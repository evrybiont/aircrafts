#ifndef STATE_H
#define STATE_H

#include "tools.h"

class State {
  protected:
    bool is_active;
    class Game *game;

    void setGame(Game*);

  public:
    State();
    virtual ~State();
    virtual void init(Game*) = 0;
};

#endif
