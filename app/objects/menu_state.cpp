#include "../heads/menu_state.h"
#include "../config/locales/menu_locale.h"

#include <iostream>

using namespace sdl;

Menu::Menu() : background(NULL) {}

Menu::~Menu() { std::cout << "MENU DELETED\n"; }

void Menu::init(Game *game) {
  setGame(game);

  Button quit_btn(QUIT);

  background = loadImage("app/images/intro_background.png");

  applySurface(0, 0, background, game->getScreen());
  applySurface(0, 0, quit_btn.get(), game->getScreen());

  SDL_Flip(game->getScreen());

  while(is_active) {
    std::cout << "Init Menu \n";
    is_active = false;
    game->stop();
  }

  SDL_Delay(2000);
}
