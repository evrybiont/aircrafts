#ifndef BUTTON_H
#define BUTTON_H

class Button {
  SDL_Surface *btn;
  SDL_Surface *btn_text;
  scope state;

  public:
    Button(std::string, int, scope);
    SDL_Surface* get();
    scope getState();
};

#endif
