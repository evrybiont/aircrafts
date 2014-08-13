#ifndef LEVEL_01_H
#define LEVEL_01_H

#include "levels_state.h"

class Level_01: public LevelsState {
  public:
    ~Level_01();
    void init(Game*);
};

#endif
