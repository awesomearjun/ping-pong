#include <SDL.h>

class Game
{
public:
    void init(const char *windowTitle, int windowX, int windowY,
              int windowWidth, int windowHeight, uint32_t windowFlags);
    void update();
    void destroy();

    static SDL_Renderer *gameRenderer;

private:
    SDL_Window *window;
};
