#ifndef PLAY_STATE_H
#define PLAY_STATE_H

#include "game.h"
#include "levels/levels_state.h"

class PlayState: public State {
  LevelsState current_level;

  public:
    void init(Game*);
};

#endif
