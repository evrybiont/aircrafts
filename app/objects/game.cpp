#include "../heads/game.h"
#include "../heads/intro_state.h"
#include "../heads/menu.h"
#include <iostream>

Intro intro;

Game::Game() : is_running(true),
               screen(SDL_SetVideoMode(SC_WIDTH, SC_HEIGHT, SC_PBB, SDL_SWSURFACE)),
               current_state(NULL),
               area(INTRO)
               {}

bool Game::isRunning() { return is_running; }

SDL_Surface* Game::getScreen() { return screen; }

void Game::stop() { is_running = false; }

void Game::setNextState() {
  std::cout << "next state \n";
  Menu menu;
  current_state = &menu;
}

void Game::chooseState() {
  std::cout << "choose\n";
  switch(area) {
    case INTRO :
      current_state = new Intro;
      break;
    case MENU :
      current_state = new Menu;
      break;
  }
}

void Game::initCurrentState() {
  std::cout << "current state\n";
  chooseState();
  current_state->init(this);
}
