#include <iostream>
#include "app/heads/init_game.h"

int main() {
  TTF_Init();

  SDL_WM_SetCaption("AirCrafts", NULL);

  while (game.isRunning()) { game.initCurrentState(); }

  TTF_Quit();
  std::cout << "Quit \n";
  return 0;
}
