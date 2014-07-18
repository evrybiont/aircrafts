#include "../heads/intro_state.h"
#include "../config/locales/intro.h"
#include <iostream>

Intro::Intro() : area(MENU) {}

int Intro::nextArea() { return area; }

void Intro::init(Game *game) {
  SDL_Surface *background = NULL;
  SDL_Surface *message = NULL;
  SDL_Surface *bottom_message = NULL;

  background = sdl::loadImage("app/images/intro_background.png");

  TTF_Init();
  TTF_Font *font = NULL;
  SDL_Color text_color = { 255, 255, 100 };
  font = TTF_OpenFont("app/fonts/InfernosSpicy.ttf", 32);

  if (font == NULL) { std::cout << TTF_GetError(); }

  message = TTF_RenderText_Solid(font, STATUS, text_color);
  bottom_message = TTF_RenderText_Solid(font, NEXT_EVENT, text_color);

  SDL_Rect offset;
  offset.x = 0;
  offset.y = 0;

  SDL_BlitSurface(background, NULL, game->getScreen(), &offset);

  offset.x = (SC_WIDTH - message->w) / 2;
  offset.y = 50;

  SDL_BlitSurface(message, NULL, game->getScreen(), &offset);

  offset.x = (SC_WIDTH - bottom_message->w) / 2;
  offset.y = 300;

  SDL_BlitSurface(bottom_message, NULL, game->getScreen(), &offset);

  Timer fps;
  SDL_Event event;
  int key_code;

  while(is_active) {
    fps.start();
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

    SDL_Flip(game->getScreen());

    sdl::delay(&fps);
  }
}
