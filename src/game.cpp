#include "game.hpp"

#include <cstdint>
#include <cstdlib>
#include <iostream>
#include <string>

#include "SDL.h"
#include "SDL_error.h"
#include "SDL_events.h"
#include "SDL_render.h"
#include "SDL_scancode.h"
#include "SDL_timer.h"
#include "SDL_ttf.h"
#include "SDL_video.h"

#include "entity.hpp"
#include "text.hpp"
#include "vector.hpp"

SDL_Renderer *Game::gameRenderer = nullptr;

int Game::init(const char *p_windowTitle, int p_windowX, int p_windowY,
               int p_windowWidth, int p_windowHeight, uint32_t p_windowFlags)
{
    if (SDL_Init(SDL_INIT_VIDEO) < 0)
    {
        std::cerr << "Problem initializing SDL: " << SDL_GetError()
                  << std::endl;
    }

    if (TTF_Init() == -1)
    {
        std::cerr << "Problem initializing SDL_ttf: " << SDL_GetError()
                  << std::endl;
    }

    window = SDL_CreateWindow(p_windowTitle, p_windowX, p_windowY,
                              p_windowWidth, p_windowHeight, p_windowFlags);

    if (window == nullptr)
        std::cerr << "Error making window: " << SDL_GetError() << std::endl;

    Game::gameRenderer = SDL_CreateRenderer(
        window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);

    if (Game::gameRenderer == nullptr)
    {
        std::cerr << "Error making gameRenderer: " << SDL_GetError()
                  << std::endl;
    }

    windowWidth = static_cast<float>(p_windowWidth);
    windowHeight = static_cast<float>(p_windowHeight);

    playerScoreInt = 0;
    enemyScoreInt = 0;

    Vec2D paddleSize = Vec2D(30, 150);
    constexpr float paddleOffset = 10;

    player.init(Vec2D(paddleOffset, windowHeight / 2 - paddleSize.y / 2),
                paddleSize);
    enemy.init(Vec2D(windowWidth - paddleSize.x - paddleOffset,
                     windowHeight / 2 - paddleSize.y / 2),
               paddleSize);
    ball.init(Vec2D((static_cast<float>(this->windowWidth) / 2) - 15,
                    (static_cast<float>(this->windowHeight) / 2) - 15),
              Vec2D(30, 30));
    ball.velocity = Vec2D(-5, -5);
    dt = 0;

    playerTextColor = {65, 105, 255, 255};
    enemyTextColor = {255, 0, 0, 255};

    playerScoreText.init("../res/fonts/Peepo.ttf", 40, "00", playerTextColor,
                         windowWidth / 4, 20);
    enemyScoreText.init("../res/fonts/Peepo.ttf", 40, "00", enemyTextColor,
                        windowWidth / 4 * 3, 20);

    return 0;
}

void Game::update()
{
    SDL_Event event;
    bool gameRunning = true;
    frameNumber = 0;

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

        player.update(playerTextColor.r, playerTextColor.g, playerTextColor.b,
                      playerTextColor.a);
        enemy.update(enemyTextColor.r, enemyTextColor.g, enemyTextColor.b,
                     enemyTextColor.a);
        ball.update(255, 255, 255, 255);

        playerScoreText.update();
        enemyScoreText.update();

        eventManager();

        SDL_RenderPresent(Game::gameRenderer);

        const uint32_t end = SDL_GetTicks();
        dt = (double)(end - start) / 1000;
        frameNumber++;
    }
}

void Game::destroy()
{
    SDL_DestroyRenderer(gameRenderer);
    SDL_DestroyWindow(window);
    SDL_Quit();
}

void Game::eventManager()
{
    const uint8_t *currentKeyState = SDL_GetKeyboardState(NULL);

    const bool up = currentKeyState[SDL_SCANCODE_UP] |
                    currentKeyState[SDL_SCANCODE_W];
    const bool down = currentKeyState[SDL_SCANCODE_DOWN] |
                      currentKeyState[SDL_SCANCODE_S];
    constexpr float playerMovementSpeed = 500;
    constexpr float botSpeedMultiplier = 0.9f;

    if (up && player.position.y > 0)
        player.velocity = Vec2D(0, -playerMovementSpeed * dt);
    else if (down && player.position.y + player.size.y < windowHeight)
        player.velocity = Vec2D(0, playerMovementSpeed * dt);
    else
        player.velocity = Vec2D(0, 0);

    if (ball.position.y < 0 || ball.position.y + ball.size.y > windowHeight)
        ball.velocity.y *= -1;

    if (ball.position.x <= player.position.x + player.size.x &&
        (ball.position.y > player.position.y &&
         ball.position.y < player.position.y + player.size.y))
    {
        // To avoid ball getting stuck
        ball.position.x = player.position.x + player.size.x + 1;

        ball.velocity.x *= -1;

        // Make ball go in y direction that player is moving
        // formula gets sign of the velocity (if not 0)
        if (player.velocity.y != 0)
        {
            ball.velocity.y = abs(ball.velocity.y) *
                              (player.velocity.y / abs(player.velocity.y));
        }

        enemyAI();
    }

    if (ball.position.x + ball.size.x > enemy.position.x &&
        (ball.position.y + ball.size.y > enemy.position.y &&
         ball.position.y < enemy.position.y + enemy.size.y))
    {
        // To avoid ball getting stuck
        ball.position.x = enemy.position.x - 1 - ball.size.y;
        ball.velocity.x *= -1;
    }

    ball.position.x += ball.velocity.x * dt;
    ball.position.y += ball.velocity.y * dt;

    // score
    if (ball.position.x + ball.size.x > windowWidth)
    {
        playerScoreInt++;
        playerScoreText.update(std::to_string(playerScoreInt));

        SDL_Delay(300);

        ball.position = Vec2D(player.position.x + player.size.x,
                              player.position.y + player.size.y / 2);
        ball.velocity.x *= -1;
    }

    if (ball.position.x < 0)
    {
        enemyScoreInt++;

        std::string buffer;

        if (std::to_string(enemyScoreInt).length() == 1)
            buffer = "0" + std::to_string(enemyScoreInt);
        else
            buffer = std::to_string(enemyScoreInt);

        enemyScoreText.update(buffer);

        SDL_Delay(300);

        ball.position = Vec2D(enemy.position.x - enemy.size.x,
                              enemy.position.y + enemy.size.y / 2);
        ball.velocity.x *= -1;
    }
}

void Game::enemyAI()
{
    // shoot a raycast
    Vec2D point = ball.position;
    Vec2D pointVelocity = ball.velocity;

    while (true)
    {
        point += pointVelocity;

        if (point.y < 0 || point.y > windowHeight)
            pointVelocity.y *= -1;

        if (point.x > enemy.position.x)
        {
            enemy.goToPos(Vec2D(enemy.position.x, point.y - enemy.size.y / 2),
                          5);
            return;
        }
    }
}
