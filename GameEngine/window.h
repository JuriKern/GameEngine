#pragma once

#include <string>

using std::string;

const int SCREEN_WIDTH = 1280;
const int SCREEN_HEIGHT = 960;
const string WINDOW_NAME = "Game 1280x960";

#include <SDL2/SDL.h>
#include <SDL2_image/SDL_image.h>

#include <string>
#include "background.h"

using std::string;

class Window
{
public:
    static Window& GetInstance();
    
    bool Init();
    void Loop();
    void Free();
    
    bool LoadBackground();
    
    ~Window();
protected:
    Window();
    
private:
    const string* mName;
    const int* mWidth;
    const int* mHeight;
    
    SDL_Window* mWindow;
    SDL_Renderer* mRenderer;
    
    Texture::Background* mBackground;
};
