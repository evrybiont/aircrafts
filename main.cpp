#include <iostream>
#include "app/heads/init_game.h"

int main() {
  SDL_WM_SetCaption("AirCrafts", NULL);

  menu.init(&game);

  while (game.isRunning()) { game.initCurrentState(); }

  return 0;
}
