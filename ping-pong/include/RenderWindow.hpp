//
//  RenderWindow.hpp
//  ping-pong
//
//  Created by OnionLord on 2025-02-16.
//

#pragma once

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

class RenderWindow {
    SDL_Window *window;
    SDL_Renderer *renderer;

public:
    RenderWindow(const char *p_title, int p_width, int p_height);
    ~RenderWindow();
};
