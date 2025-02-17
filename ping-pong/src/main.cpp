//
//  main.cpp
//  ping-pong
//
//  Created by OnionLord on 2025-02-16.
//

#include <iostream>
#include <SDL2/SDL.h>

#include "RenderWindow.hpp"
#include "Math.hpp"
#include "Entity.hpp"

#define W_WIDTH  1280
#define W_Height 720

int main(int argc, const char *argv[]) {
    if (SDL_Init(SDL_INIT_VIDEO) < 0) {
        std::cout << "Problem initializing video: " << SDL_GetError() << std::endl;
    }

    if (!IMG_Init(IMG_INIT_PNG)) {
        std::cout << "Problem initializing IMG: " << SDL_GetError() << std::endl;
    }

    RenderWindow window("Ping Pong", W_WIDTH, W_Height);

    SDL_Texture *imgTexture = window.loadTexture("img.png");
    Entity billy(Vector2f(0, 0), imgTexture);


    bool gameRunning = true;
    SDL_Event event;

    while (gameRunning) {
        while (SDL_PollEvent(&event)) {
            if (event.type == SDL_QUIT) {
                gameRunning = false;
            }
        }

        window.clear();

        window.render(billy);

        window.display();
    }

    SDL_Quit();

    return 0;
}
