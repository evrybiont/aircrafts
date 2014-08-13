#include "../heads/levels/level_01.h"
#include <iostream>

using namespace std;

Level_01::~Level_01() { cout << "LEVEL_01 DELETED\n"; }

void Level_01::init(Game *game) {
  cout << "Init Level 01" << endl;
}
