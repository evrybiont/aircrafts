#include "../heads/menu_state.h"
#include "../config/locales/menu_locale.h"

#include <iostream>

using namespace std;
using namespace sdl;

Menu::Menu() : background(NULL) {}

Menu::~Menu() { std::cout << "MENU DELETED\n"; }

void Menu::createButtons() {
  int size = (sizeof(FONTS)/sizeof(FONTS[0]));

  for(int i = 0; i < size; i++ ) {
    btn = new sdl::Button(FONTS[i]);
    buttons.push_back(btn);
  }
}

void Menu::drawButtons() {
  int size = (sizeof(FONTS)/sizeof(FONTS[0]));
  int x = SC_WIDTH/8;
  int y = SC_HEIGHT/4;

  for(int i=0; i < size; i++) {
    applySurface(x, y, buttons[i]->get(), game->getScreen());
    y += SC_HEIGHT/8;
  }
}

void Menu::init(Game *game) {
  setGame(game);
  createButtons();
  drawButtons();

  background = loadImage("app/images/intro_background.png");

  while(is_active) {
    applySurface(0, 0, background, game->getScreen());
    drawButtons();
    std::cout << "Init Menu \n";
    is_active = false;
    game->stop();
    SDL_Flip(game->getScreen());
  }

  SDL_Delay(2000);
}
