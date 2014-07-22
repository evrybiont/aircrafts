#ifndef INTRO_STATE_H
#define INTRO_STATE_H

  #include "game.h"

  class Intro: public State {
    SDL_Surface *background;
    SDL_Surface *message;
    SDL_Surface *bottom_message;

    void update();
    void clear();

    public:
      Intro();
      ~Intro();
      void init(Game*);
      void setGame(Game*);
  };

#endif
