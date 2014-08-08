#include "../heads/menu_state.h"
#include "../config/locales/menu_locale.h"

#include <iostream>

using namespace std;
using namespace sdl;

Menu::Menu() : background(NULL),
               line(SDL_CreateRGBSurface(0, 120, 1, 32, 0, 0, 0, 0)),
               y_line(SC_HEIGHT/4 + MENU_BUTTON_HEIGHT)
               {}

Menu::~Menu() { cout << "MENU DELETED\n"; }

void Menu::createButtons() {
  //fill button under-line
  SDL_FillRect(line, NULL, SDL_MapRGB(line->format, 255, 255, 100));

  int size = (sizeof(FONTS)/sizeof(FONTS[0]));

  for(int i = 0; i < size; i++ ) {
    btn = new Button(FONTS[i], MENU_BUTTON_HEIGHT);
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

  applySurface(x, y_line, line, game->getScreen());
}

void Menu::init(Game *game) {
  setGame(game);
  createButtons();

  background = loadImage("app/images/intro_background.png");

  while(is_active) {
    applySurface(0, 0, background, game->getScreen());
    drawButtons();

    is_active = false;
    game->stop();
    SDL_Flip(game->getScreen());
  }

  SDL_Delay(4000);
}
