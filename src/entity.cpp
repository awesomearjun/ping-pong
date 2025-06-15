#include "entity.hpp"

#include "SDL_render.h"
#include "game.hpp"
#include "vector.hpp"

void Entity::init(Vec2D spritePosition, Vec2D spriteSize)
{
    position = spritePosition;
	size = spriteSize;
}

void Entity::update()
{
    position += velocity;
    rect.x = position.x;
    rect.y = position.y;
	rect.w = size.x;
	rect.h = size.y;

    SDL_SetRenderDrawColor(Game::gameRenderer, 255, 255, 255, 255);
    SDL_RenderFillRect(Game::gameRenderer, &rect);
}
