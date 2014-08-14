#include "../heads/menu_state.h"
#include "../config/locales/menu_locale.h"

#include <iostream>

using namespace std;
using namespace sdl;

Menu::Menu() : background(loadImage("app/images/intro_background.png")),
               line(SDL_CreateRGBSurface(0, 120, 1, 32, 0, 0, 0, 0))
               {}

Menu::~Menu() { cout << "MENU DELETED\n"; }

void Menu::createButtons() {
  //fill button under-line
  SDL_FillRect(line, NULL, SDL_MapRGB(line->format, 255, 255, 100));

  int size = (sizeof(FONTS)/sizeof(FONTS[0]));

  for(int i = 0; i < size; i++ ) {
    btn = new Button(FONTS[i], MENU_BUTTON_HEIGHT, BUTTON_STATE[i]);
    buttons.push_back(btn);
  }

  current_btn_index = 0;
}

void Menu::drawButtons() {
  int size = (sizeof(FONTS)/sizeof(FONTS[0]));
  int x = SC_WIDTH/8;
  int y = SC_HEIGHT/4;

  for(int i=0; i < size; i++) {
    if (i == current_btn_index) { y_line = y + MENU_BUTTON_HEIGHT; }
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
    if ((current_btn_index - 1) == -1) { current_btn_index = buttons.size() - 1; }
    else { current_btn_index -= 1; }
  }
  else {
    if ((current_btn_index + 1) == buttons.size()) { current_btn_index = 0; }
    else { current_btn_index += 1; }
  }
}

void Menu::clear() {
  buttons.clear();
  applySurface(0, 0, background, game->getScreen());
  SDL_Flip(game->getScreen());
  SDL_FreeSurface(background);
  SDL_FreeSurface(line);
}

void Menu::init(Game *game) {
  setGame(game);
  createButtons();
  update();

  Timer fps;
  SDL_Event event;
  SDLKey key_pressed;

  while(is_active) {
    fps.start();

    while (SDL_PollEvent(&event)) {
      if (event.type == SDL_KEYDOWN) {
        key_pressed = event.key.keysym.sym;

        switch(key_pressed) {
        case 273 :
          update_btn(true);
          break;
        case 274 :
          update_btn(false);
          break;
        case 13 :
          game->setNextState(buttons[current_btn_index]->getState());
          is_active = false;
          break;
        }
      }
    }

    update();
    SDL_Flip(game->getScreen());
    delay(&fps);
  }

  clear();
}
