#include "window.h"

Window& Window::GetInstance()
{
    static Window _instance;
    return _instance;
}

void Window::Free()
{
    delete mBackground;

    SDL_DestroyRenderer(mRenderer);
    SDL_DestroyWindow(mWindow);
    IMG_Quit();
    SDL_Quit();
}

Window::Window() : mName(&WINDOW_NAME), mWidth(&SCREEN_WIDTH), mHeight(&SCREEN_HEIGHT), mWindow(nullptr) {}

Window::~Window() {}

bool Window::Init()
{
    if (SDL_Init(SDL_INIT_VIDEO) < 0)
        return false;
    
    SDL_SetHint(SDL_HINT_RENDER_SCALE_QUALITY, "1");
    mWindow = SDL_CreateWindow(mName->c_str(), SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, *mWidth, *mHeight, SDL_WINDOW_SHOWN);
    
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



