#include "../heads/menu.h"
#include <iostream>

Menu::~Menu() { std::cout << "MENU DELETED\n"; }

void Menu::setGame(Game *g) { game = g; }

void Menu::init(Game *game) {
  while(is_active) {
    std::cout << "Init Menu \n";
    is_active = false;
    game->stop();
  }
}
