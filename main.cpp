#include <iostream>
#include "app/heads/init_game.h"

int main() {

  while (game.isRunning()) { game.initCurrentState(); }

  return 0;
}
