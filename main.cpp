#include <iostream>
#include "app/heads/init_game.h"

int main() {

  if (game.isRunning()) { game.initCurrentState(); }

  return 0;
}
