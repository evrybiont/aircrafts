#ifndef MODAL_H
#define MODAL_H

class Modal {
  SDL_Surface *background;
  SDL_Surface *modal;

  public:
    Modal(int, int, int);
    SDL_Surface* getBackground();
    SDL_Surface* getModal();
};

#endif
