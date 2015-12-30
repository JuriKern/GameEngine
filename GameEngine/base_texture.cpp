#include "base_texture.h"

using namespace Texture;

BaseTexture::BaseTexture() : mWidth(0), mHeight(0), mTexture(nullptr) {};

BaseTexture::~BaseTexture()
{
    free();
}

void BaseTexture::free()
{
    SDL_DestroyTexture(mTexture);
    mWidth = 0;
    mHeight = 0;
    mTexture = nullptr;
}

void BaseTexture::SetRenderer(SDL_Renderer* r)
{
    mRenderer = r;
}

int BaseTexture::GetWidth() const
{
    return mWidth;
}

int BaseTexture::GetHeight() const
{
    return mHeight;
}
