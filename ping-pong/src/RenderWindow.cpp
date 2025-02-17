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

void RenderWindow::render(Entity& p_entity) {
    SDL_Rect src;
    src.x = p_entity.getCurrentFrame().x;
    src.y = p_entity.getCurrentFrame().y;
    src.w = p_entity.getCurrentFrame().w;
    src.h = p_entity.getCurrentFrame().h;

    SDL_Rect dst;
    dst.x = p_entity.getPosition().x;
    dst.y = p_entity.getPosition().y;
    dst.w = p_entity.getCurrentFrame().w * 4;
    dst.h = p_entity.getCurrentFrame().h * 4;

    SDL_RenderCopy(renderer, p_entity.getTexture(), &src, &dst);
}

SDL_Texture *RenderWindow::loadTexture(const char *p_filePath) {
    SDL_Texture *texture = NULL;
    texture = IMG_LoadTexture(renderer, p_filePath);

    if (texture == NULL) {
        std::cout << "Texture loading error: " << SDL_GetError() << std::endl;
    }

    return texture;
}
