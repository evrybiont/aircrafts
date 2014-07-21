#include "../heads/menu.h"
#include <iostream>

int Menu::nextArea() { return MENU; }

void Menu::setGame(Game *g) { game = g; }

void Menu::init(Game *game) {
  while(true) {
    std::cout << "Init Menu \n";
  }
  //game->stop();
}
