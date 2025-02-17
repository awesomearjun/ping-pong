//
//  RenderWindow.cpp
//  ping-pong
//
//  Created by OnionLord on 2025-02-16.
//

#include "RenderWindow.hpp"

#include <iostream>

RenderWindow::RenderWindow(const char *p_title, int p_width, int p_height)
:window(NULL), renderer(NULL)
{
    window = SDL_CreateWindow(p_title, SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, p_width, p_height, SDL_WINDOW_SHOWN);

    if (window == NULL) {
        std::cout << "Error with window making: " << SDL_GetError() << std::endl;
    }

    renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
}

RenderWindow::~RenderWindow() {
    SDL_DestroyWindow(window);
}
