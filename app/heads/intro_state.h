#ifndef INTRO_STATE_H
#define INTRO_STATE_H

#include "game.h"

class Intro: public State {
  scope area;

  public:
    Intro();
    void init(Game*);
    int nextArea();
};

#endif
