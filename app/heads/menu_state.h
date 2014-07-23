#ifndef MENU_STATE_H
#define MENU_STATE_H

#include "game.h"

class Menu: public State {
  SDL_Surface *background;

  public:
    Menu();
    ~Menu();
    void init(Game*);
};

#endif
