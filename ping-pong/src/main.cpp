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
#include "Utils.hpp"

#define W_WIDTH  1280
#define W_HEIGHT 720

int main(int argc, const char *argv[]) {
    if (SDL_Init(SDL_INIT_VIDEO) < 0) {
        std::cout << "Problem initializing video: " << SDL_GetError() << std::endl;
    }

    if (!IMG_Init(IMG_INIT_PNG)) {
        std::cout << "Problem initializing IMG: " << SDL_GetError() << std::endl;
    }

    RenderWindow window("Ping Pong", W_WIDTH, W_HEIGHT);

    SDL_Texture *imgTexture = window.loadTexture("img.png");
    Entity billy(Vector2f(0, 0), imgTexture, 32, 30);


    bool gameRunning = true;
    SDL_Event event;

    Vector2f force(0.01, 0);
    int oldTime = SDL_GetTicks();

    while (gameRunning) {
        int newTime = SDL_GetTicks();

        float dt = (newTime - oldTime);

        float speed = 7/4;
        Vector2f velocity(speed, 0);
        int direction = 0;

        while (SDL_PollEvent(&event)) {
            if (event.type == SDL_QUIT) {
                gameRunning = false;
            }

            if (event.key.keysym.sym == SDLK_ESCAPE) {
                gameRunning = false;
            }
        }

        const uint8_t* currentKeyStates = SDL_GetKeyboardState(NULL);

        // TODO: Make an input handler
        // This is here for now

        if (currentKeyStates[SDL_SCANCODE_D]) {
            direction = 1;
        }

        if (currentKeyStates[SDL_SCANCODE_A]) {
            direction = -1;
        }

        billy.position += velocity * direction * dt;

        // Clamp billy
        if (billy.position.x <= 0) {
            billy.position.x = 0;
        }
        if (billy.position.x + billy.spriteSize.x*4 > W_WIDTH) {
            billy.position.x = W_WIDTH - billy.spriteSize.x*4;
        }

        window.clear();
        window.render(billy);
        window.display();

        oldTime = newTime;
    }

    SDL_Quit();

    return 0;
}
