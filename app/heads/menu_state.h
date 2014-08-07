#ifndef MENU_STATE_H
#define MENU_STATE_H

#include "game.h"
#include <vector>

class Menu: public State {
  SDL_Surface *background;
  SDL_Surface *line;
  sdl::Button *btn;
  std::vector<sdl::Button*> buttons;

  void createButtons();
  void drawButtons();

  public:
    Menu();
    ~Menu();
    void init(Game*);
};

#endif
