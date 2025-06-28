#pragma once

#include <SDL.h>

#include "SDL_pixels.h"
#include "entity.hpp"
#include "text.hpp"
#include "vector.hpp"

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
	void enemyAI();

    SDL_Window *window;
	double dt;
	float windowWidth, windowHeight;

	Entity player;
	Entity enemy;
	Entity ball;

	Text playerScoreText;
	Text enemyScoreText;

	int playerScoreInt;
	int enemyScoreInt;

	SDL_Color playerTextColor;
	SDL_Color enemyTextColor;
	
	bool enemyReachedDesiredPosition;
	Vec2D enemyDesiredPosition;

	int frameNumber;
};
