#include "../heads/state.h"
#include <iostream>

State::State() :is_active(true) {}

State::~State() {}

void State::setGame(class Game *g) { game = g; }
