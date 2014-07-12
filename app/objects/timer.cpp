#include "../lib/timer.h"
#include "../lib/sdl.h"

void Timer::start() { start_time = SDL_GetTicks(); }

int Timer::getTime() { return SDL_GetTicks() - start_time; }
