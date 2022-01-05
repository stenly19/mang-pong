#include "rect.h"
#include <SDL2/SDL.h>

namespace cookie
{
    bool Rect::CollideRect(Rect &other)
    {
        return (x < other.right() &&
                right() > other.x &&
                y < other.bottom() &&
                bottom() > other.y);
    }

    void Rect::DrawRect(SDL_Renderer *renderer, Uint32 r, Uint32 g, Uint32 b, Uint32 a)
    {
        SDL_SetRenderDrawColor(renderer, r, g, b, a);
        SDL_Rect sdl_rect = SdlRect();
        SDL_RenderFillRect(renderer, &sdl_rect);
    }

    void Rect::DrawRect(SDL_Renderer *renderer, const SDL_Color &color)
    {
        SDL_SetRenderDrawColor(renderer, color.r, color.g, color.b, color.a);
        SDL_Rect sdl_rect = SdlRect();
        SDL_RenderFillRect(renderer, &sdl_rect);
    }
}