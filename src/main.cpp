#include "SDL_video.h"
#include "game.hpp"

int main()
{
    Game game;
    game.init("Ping Pong", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 1280,
              720, 0);
    game.update();
    game.destroy();
}
