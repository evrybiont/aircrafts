#include "../heads/menu_state.h"
#include <iostream>

using namespace sdl;

Menu::Menu() : background(NULL) {}

Menu::~Menu() { std::cout << "MENU DELETED\n"; }

void Menu::init(Game *game) {
  setGame(game);

  background = sdl::loadImage("app/images/intro_background.png");
  applySurface(0, 0, background, game->getScreen());
  SDL_Flip(game->getScreen());


  while(is_active) {
    std::cout << "Init Menu \n";
    is_active = false;
    game->stop();
  }
}
