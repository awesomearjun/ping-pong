#pragma once

#include <SDL.h>

#include "entity.hpp"

class Game
{
public:
    int init(const char *p_windowTitle, int p_windowX, int p_windowY,
              int p_windowWidth, int p_windowHeight, uint32_t p_windowFlags);
    void update();
    void destroy();

    static SDL_Renderer *gameRenderer;

private:
	void eventManager();

    SDL_Window *window;
	double dt;
	float windowWidth, windowHeight;

	Entity player;
	Entity enemy;
	Entity ball;

	int frameNumber;
};
