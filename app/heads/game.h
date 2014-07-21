#ifndef GAME_H
#define GAME_H

#include "state.h"

class Game {
  bool is_running;
  State *current_state;
  SDL_Surface *screen;
  enum scope { INTRO, MENU, LEVELS };
  scope area;

  void chooseState();

  public:
    Game();
    bool isRunning();
    void initCurrentState();
    SDL_Surface* getScreen();
    void stop();
    void setNextState();
};

#endif
