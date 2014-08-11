#ifndef MENU_STATE_H
#define MENU_STATE_H

#include "game.h"
#include <vector>

class Menu: public State {
  SDL_Surface *background;
  SDL_Surface *line;
  int y_line;
  sdl::Button *btn;
  int current_btn_index;
  std::vector<sdl::Button*> buttons;

  void createButtons();
  void drawButtons();
  void update();
  void update_btn(bool);

  public:
    Menu();
    ~Menu();
    void init(Game*);
};

#endif
