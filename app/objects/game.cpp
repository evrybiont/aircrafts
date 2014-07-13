#include "../heads/game.h"
#include "../lib/screen_const.h"
#include <iostream>

Game::Game() : is_running(true),
               screen(SDL_SetVideoMode(SC_WIDTH, SC_HEIGHT, SC_PBB, SDL_SWSURFACE))
               {}

bool Game::isRunning() { return is_running; }

void Game::initCurrentState() {
  std::cout << "Init current state \n";
}
