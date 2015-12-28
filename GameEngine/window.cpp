#include "window.h"

Window::Window(string n, int w, int h) : mName(n), mWidth(w), mHeight(h), mWindow(nullptr) {}

Window::~Window()
{
    delete mBackground;
    
    SDL_DestroyRenderer(mRenderer);
    SDL_DestroyWindow(mWindow);
    IMG_Quit();
    SDL_Quit();
}

bool Window::Init()
{
    if (SDL_Init(SDL_INIT_VIDEO) < 0)
        return false;
    
    SDL_SetHint(SDL_HINT_RENDER_SCALE_QUALITY, "1");
    mWindow = SDL_CreateWindow(GetName().c_str(), SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, GetWidth(), GetHeight(), SDL_WINDOW_SHOWN);
    
    if (mWindow == nullptr)
        return false;
    
    mRenderer = SDL_CreateRenderer(mWindow, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
    
    if (mRenderer == nullptr)
        return false;
    
    SDL_SetRenderDrawColor(mRenderer, 0xFF, 0xFF, 0xFF, 0xFF);
    
    int imgFlags = IMG_INIT_PNG;
    if (!(IMG_Init(imgFlags) & imgFlags))
        return false;
    
    return true;
}

void Window::Loop()
{
    bool quit = false;
    SDL_Event e;
    
    while (!quit)
    {
        while (SDL_PollEvent(&e) != 0)
        {
            if (e.type == SDL_QUIT)
                quit = true;
        }
        
        SDL_SetRenderDrawColor(mRenderer, 0xFF, 0xFF, 0xFF, 0xFF);
        SDL_RenderClear(mRenderer);
        mBackground->Render(0, 0);
        SDL_RenderPresent(mRenderer);
    }
}

bool Window::LoadBackground()
{
    mBackground = new Texture::Background;
    mBackground->SetRenderer(mRenderer);
    
    if (!mBackground->Init())
        return false;
    
    return true;
}

string Window::GetName() const
{
    return mName;
}

int Window::GetWidth() const
{
    return mWidth;
}

int Window::GetHeight() const
{
    return mHeight;
}



