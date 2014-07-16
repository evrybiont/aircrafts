#ifndef TIMER_H
#define TIMER_H

#include "../lib/init_sdl.h"

class Timer {
  int start_time;

  public:
    void start();
    int getTime();
};

#endif
