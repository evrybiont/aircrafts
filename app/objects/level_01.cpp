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
  SDL_Event event;
  SDLKey key_pressed;

  while(is_running) {
    fps.start();
    applySurface(0, 0, background, game->getScreen());

    while (SDL_PollEvent(&event)) {
      if (event.type == SDL_KEYDOWN) {
        key_pressed = event.key.keysym.sym;

        switch(key_pressed) {
          case 27 : //ESC
            cout << "ESC PRESSED" << endl;
            break;
          case 13 :
            is_running = false;
            game->stop();
            break;
        }
      }
    }

    SDL_Flip(game->getScreen());
    delay(&fps);
  }
}
