#ifndef QUIT_STATE_H
#define QUIT_STATE_H

#include "game.h"

class QuitState: public State {
  public:
    void init(Game*);
};

#endif
