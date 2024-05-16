#include "global.hpp"
#include "system.hpp"

int main() {
  System *game = new System(WIDTH, HEIGHT);
  game->run();
  delete game;
  return 0;
}

/////
