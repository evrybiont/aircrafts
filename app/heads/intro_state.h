#ifndef INTRO_STATE_H
#define INTRO_STATE_H

  #include "game.h"

  class Intro: public State {
    scope area;
    Game *game;

    SDL_Surface *background;
    SDL_Surface *message;
    SDL_Surface *bottom_message;

    void update();

    public:
      Intro();
      void init(Game*);
      int nextArea();
      void setGame(Game*);
  };

#endif
