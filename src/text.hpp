#pragma once

#include "SDL_pixels.h"
#include "SDL_render.h"
#include <string>

class Text
{
public:
    void init(const std::string &fontPath, int fontSize,
              const std::string &messsageText, const SDL_Color &color, int x,
              int y);
    void update() const;
	void update(const std::string &newMessage);
    static SDL_Texture *loadFont(const std::string &fontPath, int font_size,
                                 const std::string &messsageText,
                                 const SDL_Color &color);

private:
    SDL_Texture *textTexture;
    SDL_Rect textRect;
    std::string fontPath;
    int fontSize;
    SDL_Color fontColor;
};
