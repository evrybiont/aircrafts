#include <iostream>
#include "app/heads/init_game.h"

int main() {
  std::cout << "Main Function\n";

  game.initCurrentState();
  Intro intro;
  intro.init();
  intro.nextArea();
  return 0;
}
