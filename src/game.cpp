#include "game.hpp"

#include <cstdint>
#include <iostream>

#include "SDL.h"
#include "SDL_error.h"
#include "SDL_events.h"
#include "SDL_render.h"
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
}

void Game::update()
{
    SDL_Event event;
    bool gameRunning = true;

    while (gameRunning)
    {
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

        SDL_RenderPresent(Game::gameRenderer);
    }
}

void Game::destroy()
{
    SDL_DestroyRenderer(gameRenderer);
    SDL_DestroyWindow(window);
    SDL_Quit();
}
