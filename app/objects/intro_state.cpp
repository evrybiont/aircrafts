#include "../heads/intro_state.h"
#include "../config/locales/intro_locale.h"
#include <iostream>

  using namespace sdl;

  Intro::Intro() : background(NULL),
                   message(NULL),
                   bottom_message(NULL) {}

  Intro::~Intro() { std::cout << "INTRO DELETED\n"; }

  void Intro::update() {
    blink(bottom_message);
    applySurface(0, 0, background, game->getScreen());
    applySurface(((SC_WIDTH - message->w) / 2), 50, message, game->getScreen());
    applySurface(((SC_WIDTH - bottom_message->w) / 2), 300, bottom_message, game->getScreen());
  }

  void Intro::clear(){
    freeBlink();
    SDL_FreeSurface(background);
    SDL_FreeSurface(message);
    SDL_FreeSurface(bottom_message);
  }

  void Intro::init(Game *game) {
    setGame(game);

    background = sdl::loadImage("app/images/intro_background.png");

    TTF_Font *font = NULL;
    SDL_Color text_color = { 255, 255, 100 };
    font = TTF_OpenFont("app/fonts/InfernosSpicy.ttf", 32);

    if (font == NULL) { std::cout << TTF_GetError(); }

    message = TTF_RenderText_Solid(font, STATUS, text_color);
    bottom_message = TTF_RenderText_Solid(font, NEXT_EVENT, text_color);

    Timer fps;
    SDL_Event event;
    int key_code;

    while(is_active) {
      fps.start();

      update();

      while (SDL_PollEvent(&event)) {
        key_code = event.key.keysym.sym;

        if (key_code == 32) {
          is_active = false;
          game->setNextState(MENU);
          break;
        }

        if (event.type == SDL_QUIT) {
          is_active = false;
          game->stop();
        }
      }

      SDL_Flip(game->getScreen());

      delay(&fps);
    }

    clear();
  }
