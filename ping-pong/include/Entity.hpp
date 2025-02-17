//
//  Entity.hpp
//  ping-pong
//
//  Created by OnionLord on 2025-02-17.
//

#pragma once

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include "Math.hpp"

class Entity {
private:
    Vector2f position;
    SDL_Rect currentFrame;
    SDL_Texture *texture;
    
public:
    Entity(Vector2f p_position, SDL_Texture *p_texture);
    SDL_Texture *getTexture() {
        return texture;
    }

    SDL_Rect getCurrentFrame() {
        return currentFrame;
    }

    Vector2f getPosition() {
        return position;
    }
};
