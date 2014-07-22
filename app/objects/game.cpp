#include "../heads/game.h"
#include "../heads/intro_state.h"
#include "../heads/menu.h"
#include <iostream>

Game::Game() : is_running(true),
               screen(SDL_SetVideoMode(SC_WIDTH, SC_HEIGHT, SC_PBB, SDL_SWSURFACE)),
               current_state(NULL),
               area(INTRO)
               {}

bool Game::isRunning() { return is_running; }

SDL_Surface* Game::getScreen() { return screen; }

void Game::stop() { is_running = false; }

void Game::setNextState(scope state) { area = state; }

void Game::chooseState() {

  if(current_state) {
    delete current_state;
    current_state = NULL;
  }

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
  chooseState();
  current_state->init(this);
}
