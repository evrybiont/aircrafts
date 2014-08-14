#include "../lib/sdl_space.h"
#include <iostream>

namespace sdl {
  const int FPS = 20;
  int trans = 0;    // only for blink !!!
  bool in = true;  // only for blink !!!

  void freeBlink() {
    trans = 0;
    in = true;
  }

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

  void applySurface(int x, int y, SDL_Surface *source, SDL_Surface *destination, SDL_Rect *clip) {
    SDL_Rect offset;

    offset.x = x;
    offset.y = y;

    SDL_BlitSurface(source, clip, destination, &offset);
  }

  int getTrans() {
    if (in) { trans += 10;
      if (trans == 250) { in = false; } }
    else { trans -= 10;
      if (trans == 0) { in = true; } }
  }

  void blink(SDL_Surface *source) {
    SDL_SetAlpha(source, SDL_SRCALPHA, getTrans());
  }

// Button class

sdl::Button::Button(std::string text, int size, scope area) {
  state = area;
  btn_text = NULL;

  TTF_Font *font = NULL;
  SDL_Color text_color = { 255, 255, 100 };
  font = TTF_OpenFont("app/fonts/InfernosSpicy.ttf", size);

  if (font == NULL) { std::cout << TTF_GetError(); }

  btn_text = TTF_RenderText_Solid(font, text.c_str(), text_color);
}

SDL_Surface* sdl::Button::get() { return btn_text; }

scope sdl::Button::getState() { return state; }

// Button class end

// Modal class

sdl::Modal::Modal(int w, int h) {
  modal = SDL_CreateRGBSurface(0, w, h, 32, 0, 0, 0, 0);
}

// Modal class end
}
