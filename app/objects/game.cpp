#include "../heads/game.h"
#include "../heads/intro_state.h"
#include <iostream>

Intro intro;

Game::Game() : is_running(true),
               screen(SDL_SetVideoMode(SC_WIDTH, SC_HEIGHT, SC_PBB, SDL_SWSURFACE)),
               current_state(&intro)
               {}

bool Game::isRunning() { return is_running; }

SDL_Surface* Game::getScreen() { return screen; }

void Game::stop() { is_running = false; }

void Game::initCurrentState() {
  current_state->init(this);
}
