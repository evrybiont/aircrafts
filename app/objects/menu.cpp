#include "../heads/menu.h"
#include <iostream>

int Menu::nextArea() { return MENU; }

void Menu::init(Game *g) {
  std::cout << "Init Menu \n";
}
