#pragma once

#include <SDL2/SDL.h>
#include <SDL2_image/SDL_image.h>

namespace Texture
{
    class Background
    {
    public:
        Background();
        ~Background();
        
        void Free();
        void SetRenderer(SDL_Renderer* r);
        
        bool Init();
        void Render(int x, int y);
        
        int GetWidth() const;
        int GetHeight() const;
    private:
        SDL_Texture* mTexture;
        SDL_Renderer* mRenderer;
        
        int mWidth;
        int mHeight;
    };
}