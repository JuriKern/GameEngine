#include <string>
#include "background.h"

using namespace Texture;
using std::string;

Background::Background() : mWidth(0), mHeight(0), mTexture(nullptr) {}
Background::~Background()
{
    free();
}

void Background::free()
{
    SDL_DestroyTexture(mTexture);
    mWidth = 0;
    mHeight = 0;
    mTexture = nullptr;
}

void Background::SetRenderer(SDL_Renderer* r)
{
    mRenderer = r;
}

bool Background::Init()
{
    free();
    
    SDL_Texture* newTexture = nullptr;
    string path = "Images/bg.png";
    
    SDL_Surface* loadedSurface = IMG_Load(path.c_str());
    if (loadedSurface == nullptr)
        return false;
    else
    {
        SDL_SetColorKey(loadedSurface, SDL_TRUE, SDL_MapRGB(loadedSurface->format, 0, 0xFF, 0xFF));
        
        newTexture = SDL_CreateTextureFromSurface(mRenderer, loadedSurface);
        
        if (newTexture)
        {
            mWidth = loadedSurface->w;
            mHeight = loadedSurface->h;
        }
    
        mTexture = newTexture;
    }
    
    SDL_FreeSurface(loadedSurface);
    loadedSurface = nullptr;
    
    return true;
}

void Background::Render(int x, int y)
{    
    SDL_Rect renderQuad = { x, y, mWidth, mHeight };
    SDL_RenderCopy(mRenderer, mTexture, nullptr, &renderQuad);
}

int Background::GetWidth() const
{
    return mWidth;
}

int Background::GetHeight() const
{
    return mHeight;
}
