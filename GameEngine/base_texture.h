#pragma once

#include <SDL2/SDL.h>

namespace Texture
{
    class BaseTexture
    {
    public:
        BaseTexture();
        ~BaseTexture();
        
        void SetRenderer(SDL_Renderer* r);
        
        virtual bool Init() = 0;
        virtual void Render(int x, int y) = 0;
        
        int GetWidth() const;
        int GetHeight() const;
        
    protected:
        void free();

        SDL_Texture* mTexture;
        SDL_Renderer* mRenderer;
        
        int mWidth;
        int mHeight;
    };
}
