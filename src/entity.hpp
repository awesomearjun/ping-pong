#pragma once

#include "SDL_rect.h"
#include "vector.hpp"

class Entity
{
public:
	void init(int x, int y, int w, int h);
	void update();
	Vec2D position;
private:
	SDL_Rect rect;
};
