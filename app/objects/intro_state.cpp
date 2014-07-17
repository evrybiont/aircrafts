#include "../heads/intro_state.h"
#include "../config/locales/intro.h"
#include <iostream>

Intro::Intro() : area(MENU) {}

int Intro::nextArea() { return area; }

void Intro::init(Game *game) {
  SDL_Surface *background = NULL;
  SDL_Surface *message = NULL;

  background = sdl::loadImage("app/images/intro_background.png");

  if (!background) { std::cout << "Background not found"; }

  TTF_Init();
  TTF_Font *font = NULL;
  SDL_Color text_color = { 255, 255, 100 };
  font = TTF_OpenFont("app/fonts/InfernosSpicy.ttf", 32);

  if (font == NULL) { std::cout << TTF_GetError(); }

  message = TTF_RenderText_Solid( font, STATUS, text_color );

  SDL_Rect offset;
  offset.x = 0;
  offset.y = 0;

  SDL_BlitSurface(background, NULL, game->getScreen(), &offset);
  SDL_BlitSurface(message, NULL, game->getScreen(), &offset);

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
