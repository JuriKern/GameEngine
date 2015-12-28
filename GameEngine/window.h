#pragma once

#include <SDL2/SDL.h>
#include <SDL2_image/SDL_image.h>

#include <string>

using std::string;

class Window
{
public:
    Window(string n, int m, int h);
    ~Window();
    
    bool Init();
    void Loop();
    
    string GetName() const;
    int GetWidth() const;
    int GetHeight() const;
private:
    const string mName;
    const int mWidth;
    const int mHeight;
    
    SDL_Window* mWindow;
    SDL_Renderer* mRenderer;
};
