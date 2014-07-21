#ifndef MENU_H
#define MENU_H

#include "game.h"

class Menu: public State {

  public:
    void init(Game*);
    int nextArea();
    void setGame(Game*);
};

#endif
