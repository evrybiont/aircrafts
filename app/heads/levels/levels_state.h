#ifndef LEVELS_STATE_H
#define LEVELS_STATE_H

#include "../game.h"

class LevelsState {
  protected:
    SDL_Surface *background;
    bool is_running;

  public:
    LevelsState();
    virtual ~LevelsState();
    virtual void init(Game*);
};

#endif
