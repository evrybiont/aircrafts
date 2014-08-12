#ifndef SDL_SPACE_H
#define SDL_SPACE_H

#include "timer.h"
#include "game_const.h"

namespace sdl {

  void delay(Timer*);

  SDL_Surface *loadImage(std::string);

  void applySurface(int, int, SDL_Surface*, SDL_Surface*, SDL_Rect *clip = NULL);

  void blink(SDL_Surface*);

  void freeBlink();

  class Button {
    SDL_Surface *btn;
    SDL_Surface *btn_text;
    scope state;

    public:
      Button(std::string, int, scope);
      SDL_Surface* get();
      scope getState();
  };
}

#endif
