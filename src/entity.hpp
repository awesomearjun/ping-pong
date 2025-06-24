#pragma once

#include "SDL_rect.h"
#include "vector.hpp"

class Entity
{
public:
	void init(Vec2D spritePosition, Vec2D spriteSize);
	void update(uint32_t red, uint32_t green, uint32_t blue, uint32_t alpha);

    Vec2D velocity;
    Vec2D position;
	Vec2D size;

private:
    SDL_Rect rect;
};
