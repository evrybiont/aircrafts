#include "../heads/game.h"
#include "../heads/intro_state.h"
#include "../lib/screen_const.h"
#include <iostream>

Intro intro;

Game::Game() : is_running(true),
               screen(SDL_SetVideoMode(SC_WIDTH, SC_HEIGHT, SC_PBB, SDL_SWSURFACE)),
               current_state(&intro)
               {}

bool Game::isRunning() { return is_running; }

void Game::initCurrentState() {
  current_state->init();
}
