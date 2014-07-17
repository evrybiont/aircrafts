#ifndef SDL_SPACE_H
#define SDL_SPACE_H

#include "timer.h"

namespace sdl {

  void delay(Timer*);

  SDL_Surface *loadImage(std::string);
}

#endif
