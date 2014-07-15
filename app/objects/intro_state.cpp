#include "../heads/intro_state.h"
#include <iostream>

Intro::Intro() : area(MENU) {}

int Intro::nextArea() { return area; }

void Intro::init(Game *game) {
  SDL_Surface *screen = NULL;
  screen = game->getScreen();

  std::cout << "init Intro State \n";

  SDL_Event event;
  int key_code;

  while(is_active) {
    while (SDL_PollEvent(&event)) {
      key_code = event.key.keysym.sym;

      if (key_code == SDLK_ESCAPE || key_code == SDLK_SPACE) {
        is_active = false;
        break;
      }

      if (event.type == SDL_QUIT) {
        is_active = false;
        game->stop();
      }
    }
  }
}
