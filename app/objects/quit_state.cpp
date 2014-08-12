#include "../heads/quit_state.h"
#include <iostream>

void QuitState::init(Game *game) {
  game->stop();
}
