#include "../heads/menu_state.h"
#include "../config/locales/menu_locale.h"

#include <iostream>

using namespace std;
using namespace sdl;

Menu::Menu() : background(loadImage("app/images/intro_background.png")),
               line(SDL_CreateRGBSurface(0, 120, 1, 32, 0, 0, 0, 0)),
               y_line(SC_HEIGHT/4 + MENU_BUTTON_HEIGHT),
               current_btn_index(1)
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

void Menu::update() {
  applySurface(0, 0, background, game->getScreen());
  drawButtons();
}

void Menu::update_btn(bool up) {
  if (up) {
    if ((current_btn_index - 1) == 0) { current_btn_index = buttons.size(); }
    else { current_btn_index -= 1; }
  }
  else {
    if ((current_btn_index + 1) == buttons.size() + 1) { current_btn_index = 1; }
    else { current_btn_index += 1; }
  }
}

void Menu::init(Game *game) {
  setGame(game);
  createButtons();
  update();

  Timer fps;
  Uint8 *keys = SDL_GetKeyState(NULL);

  while(is_active) {
    fps.start();

    if( keys[ SDLK_UP ]) {
      update_btn(true);
      update();
    }

    if( keys[ SDLK_DOWN ]) {
      update_btn(false);
      update();
    }

    if( keys[ SDLK_RETURN ]) {
      //game->setNextState(state());
      is_active = false;
      game->stop();
    }

    SDL_Flip(game->getScreen());
    SDL_PumpEvents();
    delay(&fps);
  }
}
