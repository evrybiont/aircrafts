#include "../lib/timer.h"

void Timer::start() { start_time = SDL_GetTicks(); }

int Timer::getTime() { return SDL_GetTicks() - start_time; }
