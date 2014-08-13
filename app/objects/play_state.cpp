#include "../heads/play_state.h"
#include <iostream>

using namespace std;

void PlayState::init(Game *game) {
  while(is_active) {
    cout << "Play init" << endl;
    is_active = false;
    game->stop();
  }
}
