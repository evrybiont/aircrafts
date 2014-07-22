#ifndef MENU_H
#define MENU_H

#include "game.h"

class Menu: public State {

  public:
    ~Menu();
    void init(Game*);
    void setGame(Game*);
};

#endif
