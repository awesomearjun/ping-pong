//
//  Entity.cpp
//  ping-pong
//
//  Created by OnionLord on 2025-02-17.
//

#include "Entity.hpp"

Entity::Entity(Vector2f p_position, SDL_Texture *p_texture, int p_width, int p_height)
:position(p_position), texture(p_texture)
{
    spriteSize = Vector2f(p_width, p_height);
    currentFrame.x = 0;
    currentFrame.y = 0;
    currentFrame.w = spriteSize.x;
    currentFrame.h = spriteSize.y;
}
