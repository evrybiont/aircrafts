#include "../heads/menu_state.h"
#include "../config/locales/menu_locale.h"

#include <iostream>

using namespace std;
using namespace sdl;

Menu::Menu() : background(NULL) {}

Menu::~Menu() { std::cout << "MENU DELETED\n"; }

void Menu::createButtons() {
  int size = (sizeof(fonts)/sizeof(fonts[0]));

  for (int i = 0; i < size; i++ ) {
    btn = new sdl::Button(fonts[i]);
    buttons.push_back(btn);
  }
}

void Menu::init(Game *game) {
  setGame(game);
  createButtons();

  background = loadImage("app/images/intro_background.png");

  applySurface(0, 0, background, game->getScreen());
  applySurface(0, 0, buttons[0]->get(), game->getScreen());
  applySurface(0, 100, buttons[1]->get(), game->getScreen());

  SDL_Flip(game->getScreen());

  while(is_active) {
    std::cout << "Init Menu \n";
    is_active = false;
    game->stop();
  }

  SDL_Delay(2000);
}
