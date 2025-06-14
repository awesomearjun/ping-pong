#include "entity.hpp"

#include "SDL_render.h"
#include "game.hpp"

void Entity::init(int x, int y, int w, int h)
{
    position.x = x;
    position.y = y;
	size.x = w;
	size.y = h;
}

void Entity::update()
{
    position += velocity;
    rect.x = position.x;
    rect.y = position.y;
	rect.w = size.x;
	rect.h = size.y;

    SDL_SetRenderDrawColor(Game::gameRenderer, 255, 255, 255, 255);
    SDL_RenderDrawRect(Game::gameRenderer, &rect);
}
