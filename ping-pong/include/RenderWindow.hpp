//
//  RenderWindow.hpp
//  ping-pong
//
//  Created by OnionLord on 2025-02-16.
//

#pragma once

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

#include "Entity.hpp"

class RenderWindow {
private:
    SDL_Window *window;
    SDL_Renderer *renderer;
    
public:
    RenderWindow(const char *p_title, int p_width, int p_height);
    ~RenderWindow();
    void render(Entity& p_entity);
    SDL_Texture *loadTexture(const char *p_filePath);
    void clear() {
        SDL_RenderClear(renderer);
    }

    void display() {
        SDL_RenderPresent(renderer);
    }
};
