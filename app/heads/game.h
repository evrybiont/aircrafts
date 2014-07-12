#ifndef GAME_H
#define GAME_H

#include "../lib/sdl.h"

class Game {
  bool is_running;
  SDL_Surface *screen;

  public:
    Game();
    bool isRunning();
    void initCurrentState();
};

#endif
