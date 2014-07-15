#include "../lib/sdl_space.h"

namespace sdl {
  const int FPS = 5;

  void delay(Timer *fps) {
    if(fps->getTime() < 1000/FPS) {
      SDL_Delay((1000/FPS) - fps->getTime());
    }
  }
}
