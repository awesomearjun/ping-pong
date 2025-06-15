#pragma once

#include "SDL_rect.h"
#include "vector.hpp"

class Entity
{
public:
	void init(Vec2D spritePosition, Vec2D spriteSize);
    void update();

    Vec2D velocity;
    Vec2D position;
	Vec2D size;

private:
    SDL_Rect rect;
};
