#include "entity.hpp"

#include "SDL_render.h"
#include "game.hpp"
#include "vector.hpp"
#include <cstdint>

void Entity::init(Vec2D spritePosition, Vec2D spriteSize)
{
    position = spritePosition;
	size = spriteSize;
}

void Entity::update(uint32_t red, uint32_t green, uint32_t blue, uint32_t alpha)
{
    position += velocity;
    rect.x = position.x;
    rect.y = position.y;
	rect.w = size.x;
	rect.h = size.y;

    SDL_SetRenderDrawColor(Game::gameRenderer, red, green, blue, alpha);
    SDL_RenderFillRect(Game::gameRenderer, &rect);
}
