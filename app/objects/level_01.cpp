#include "../heads/levels/level_01.h"
#include <iostream>

using namespace std;
using namespace sdl;

Level_01::Level_01() {}

Level_01::~Level_01() { cout << "LEVEL_01 DELETED\n"; }

void Level_01::init(Game *game) {
  Modal menu(400, 200, 100);

  is_running = true;
  background = loadImage("app/images/level_01/background.png");

  Timer fps;
  SDL_Flip(game->getScreen());

  while(is_running) {
    applySurface(0, 0, background, game->getScreen());
    //fps.start();
    is_running = false;
    SDL_Flip(game->getScreen());
    //delay(&fps);
  }
  SDL_Delay(4000);
}
