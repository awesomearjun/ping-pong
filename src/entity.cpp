#include "entity.hpp"

#include "SDL_render.h"
#include "game.hpp"
#include "vector.hpp"
#include <algorithm>
#include <cstdint>
#include <cstdlib>

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

void Entity::goToPos(const Vec2D &desiredPosition, const float &maxSpeed)
{
//    if (position.x != desiredPosition.x || position.y != desiredPosition.y)
//    {
//        float diffX = position.x - desiredPosition.x;
//        float diffY = position.y - desiredPosition.y;
//        if (diffX != 0)
//            velocity.x = maxSpeed * (diffX / std::abs(diffX));
//        if (diffY != 0)
//            velocity.y = maxSpeed * (diffY / std::abs(diffY));
//    }
//    else
//    {
//        velocity.x = 0;
//        velocity.y = 0;
	this->position.y = desiredPosition.y;
}
