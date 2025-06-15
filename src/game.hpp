#pragma once

#include <SDL.h>

#include "entity.hpp"

class Game
{
public:
    void init(const char *windowTitle, int windowX, int windowY,
              int windowWidth, int windowHeight, uint32_t windowFlags);
    void update();
    void destroy();

    static SDL_Renderer *gameRenderer;

private:
	void eventManager();

    SDL_Window *window;
	double dt;
	int windowWidth, windowHeight;

	Entity player;
	Entity ball;
};
