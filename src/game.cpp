#include "game.hpp"

#include <cstdint>
#include <iostream>

#include "SDL.h"
#include "SDL_error.h"
#include "SDL_events.h"
#include "SDL_render.h"
#include "SDL_scancode.h"
#include "SDL_video.h"

#include "entity.hpp"

SDL_Renderer *Game::gameRenderer = nullptr;

void Game::init(const char *windowTitle, int windowX, int windowY,
                int windowWidth, int windowHeight, uint32_t windowFlags)
{
    if (SDL_Init(SDL_INIT_VIDEO) < 0)
    {
        std::cerr << "Problem initializing SDL: " << SDL_GetError()
                  << std::endl;
    }

    window = SDL_CreateWindow(windowTitle, windowX, windowY, windowWidth,
                              windowHeight, windowFlags);

    if (window == nullptr)
        std::cerr << "Error making window: " << SDL_GetError() << std::endl;

    Game::gameRenderer = SDL_CreateRenderer(
        window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);

    if (Game::gameRenderer == nullptr)
    {
        std::cerr << "Error making gameRenderer: " << SDL_GetError()
                  << std::endl;
    }

    player.init(7, 7, 30, 150);
    this->windowWidth = windowWidth;
    this->windowHeight = windowHeight;
}

void Game::update()
{
    SDL_Event event;
    bool gameRunning = true;

    while (gameRunning)
    {
        const uint32_t start = SDL_GetTicks();

        while (SDL_PollEvent(&event))
        {
            switch (event.type)
            {
            case SDL_QUIT:
                gameRunning = false;
                break;
            }
        }

        SDL_SetRenderDrawColor(Game::gameRenderer, 0, 0, 0, 255);
        SDL_RenderClear(Game::gameRenderer);

        player.update();

        keyboardManager();

        SDL_RenderPresent(Game::gameRenderer);

        const uint32_t end = SDL_GetTicks();
        dt = (double)(end - start) / 1000;
    }
}

void Game::destroy()
{
    SDL_DestroyRenderer(gameRenderer);
    SDL_DestroyWindow(window);
    SDL_Quit();
}

void Game::keyboardManager()
{
    const uint8_t *currentKeyState = SDL_GetKeyboardState(NULL);

    const bool up = currentKeyState[SDL_SCANCODE_UP] |
                    currentKeyState[SDL_SCANCODE_W];
    const bool down = currentKeyState[SDL_SCANCODE_DOWN] |
                      currentKeyState[SDL_SCANCODE_S];
    constexpr float playerMovementSpeed = 500;

    if (up && player.position.y > 0)
        player.velocity = Vec2D(0, -playerMovementSpeed * dt);
    else if (down && player.position.y + player.size.y < windowHeight)
        player.velocity = Vec2D(0, playerMovementSpeed * dt);
    else
        player.velocity = Vec2D(0, 0);
}
