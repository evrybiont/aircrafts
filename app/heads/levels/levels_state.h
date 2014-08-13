#ifndef LEVELS_STATE_H
#define LEVELS_STATE_H

#include "../game.h"

class LevelsState {
  public:
    virtual ~LevelsState();
    virtual void init(Game*);
};

#endif
