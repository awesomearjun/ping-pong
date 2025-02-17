//
//  Entity.cpp
//  ping-pong
//
//  Created by OnionLord on 2025-02-17.
//

#include "Entity.hpp"

Entity::Entity(Vector2f p_position, SDL_Texture *p_texture)
:position(p_position), texture(p_texture)
{
    currentFrame.x = 0;
    currentFrame.y = 0;
    currentFrame.w = 32;
    currentFrame.h = 32;
}
