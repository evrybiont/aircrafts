#include "../heads/play_state.h"
#include "../heads/levels/level_01.h"
#include <iostream>

using namespace std;
using namespace sdl;

PlayState::PlayState() : level(LEVEL_01) {}

void PlayState::chooseLevel() {

  if(current_level) {
    delete current_level;
    current_level = NULL;
  }

  switch(level) {
    case LEVEL_01 :
      current_level = new Level_01;
      break;
  }
}


void PlayState::init(Game *game) {
  Timer fps;

  while(is_active) {
    fps.start();
    chooseLevel();
    current_level->init(game);
    is_active = false;
    game->stop();
    delay(&fps);
  }
}
