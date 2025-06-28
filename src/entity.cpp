#include "entity.hpp"

#include "SDL_render.h"
#include "game.hpp"
#include "vector.hpp"
#include <algorithm>
#include <cmath>
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

void Entity::goToPos(const Vec2D &desiredPosition, const float &maxSpeed, bool &reachedPos)
{
    Vec2D direction =
        Vec2D(desiredPosition.x - position.x, desiredPosition.y - position.y);
    float distance = hypot(direction.x, direction.y);

	direction.x /= distance;
	direction.y /= distance;

    if (distance > maxSpeed)
    {
        velocity = Vec2D(direction.x * maxSpeed, direction.y * maxSpeed);
    }
    else
    {
        velocity = Vec2D(direction.x * distance, direction.y * distance);

        if (distance < 1.0f)
        {
            position = desiredPosition;
            velocity = Vec2D(0, 0);
			reachedPos = true;
        }
    }
}
