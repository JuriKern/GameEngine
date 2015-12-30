#pragma once

#include <SDL2/SDL.h>
#include <SDL2_image/SDL_image.h>

#include "base_texture.h"

namespace Texture
{
    class Background : public Texture::BaseTexture
    {
    public:
        Background();
        ~Background();
        
        bool Init();
        void Render(int x, int y);
    };
}