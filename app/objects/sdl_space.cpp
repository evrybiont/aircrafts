#include "../lib/sdl_space.h"
#include <iostream>

namespace sdl {
  const int FPS = 10;

  void delay(Timer *fps) {
    if(fps->getTime() < 1000/FPS) {
      SDL_Delay((1000/FPS) - fps->getTime());
    }
  }

  SDL_Surface *loadImage(std::string path) {
    SDL_Surface *image = NULL;
    SDL_Surface *optimezed_image = NULL;

    image = IMG_Load(path.c_str());

    if (!image) { std::cout << "IMG_Load: \n" << "\t" << IMG_GetError(); return NULL; }

    SDL_SetColorKey(image, SDL_SRCCOLORKEY, SDL_MapRGBA(image->format, 255, 255, 255, 255));

    if (image) {
      optimezed_image = SDL_DisplayFormat(image);
      SDL_FreeSurface(image);
    }

    return optimezed_image;
  }
}
