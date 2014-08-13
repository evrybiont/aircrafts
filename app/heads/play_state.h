#ifndef PLAY_STATE_H
#define PLAY_STATE_H

#include "levels/levels_state.h"

class PlayState: public State {
  LevelsState *current_level;
  levels level;

  void chooseLevel();

  public:
    PlayState();
    void init(Game*);
};

#endif
