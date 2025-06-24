#include "text.hpp"

#include "SDL_error.h"
#include "SDL_render.h"
#include "SDL_surface.h"
#include "SDL_ttf.h"
#include <iostream>

#include "game.hpp"

void Text::init(const std::string &fontPath, int fontSize,
                const std::string &messsageText, const SDL_Color &color, int x,
                int y)
{
    this->fontPath = fontPath;
    this->fontSize = fontSize;
    this->fontColor = color;
    textTexture = Text::loadFont(fontPath, fontSize, messsageText, color);
    SDL_QueryTexture(textTexture, nullptr, nullptr, &textRect.w, &textRect.h);

    textRect.x = x;
    textRect.y = y;
}

void Text::update() const
{
    SDL_RenderCopy(Game::gameRenderer, textTexture, nullptr, &textRect);
}

void Text::update(const std::string &newMessage)
{
    SDL_DestroyTexture(textTexture);
    textTexture = Text::loadFont(fontPath, fontSize, newMessage, fontColor);

    Text::update();
}

SDL_Texture *Text::loadFont(const std::string &fontPath, int font_size,
                            const std::string &messsageText,
                            const SDL_Color &color)
{
    TTF_Font *font = TTF_OpenFont(fontPath.c_str(), font_size);
    if (!font)
        std::cerr << "Failed to load font: " << SDL_GetError() << std::endl;

    SDL_Surface *textSurface =
        TTF_RenderText_Solid(font, messsageText.c_str(), color);

    if (!textSurface)
    {
        std::cerr << "Failed to make text surface: " << SDL_GetError()
                  << std::endl;
    }

    SDL_Texture *textTexture =
        SDL_CreateTextureFromSurface(Game::gameRenderer, textSurface);

    if (!textTexture)
    {
        std::cerr << "Failed to make text texure: " << SDL_GetError()
                  << std::endl;
    }

    SDL_FreeSurface(textSurface);

    return textTexture;
}
