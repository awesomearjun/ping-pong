#include "entity.hpp"

#include <iostream>

#include "SDL_render.h"
#include "game.hpp"

void Entity::init(int x, int y, int w, int h)
{
    position.x = x;
    position.y = y;
    rect.w = w;
    rect.h = h;
    std::cout << "Position: " << position << ", Rect: " << rect.w << ", "
              << rect.h << std::endl;
}

void Entity::update()
{
    rect.x = position.x;
    rect.y = position.y;

    std::cout << "X: " << rect.x << ", Y: " << rect.y << ", W: " << rect.w
              << "H: " << rect.h << std::endl;

    SDL_SetRenderDrawColor(Game::gameRenderer, 255, 255, 255, 255);
    SDL_RenderDrawRect(Game::gameRenderer, &rect);
}
