#include <iostream>

#include <SDL2/SDL.h>
#include <SDL2_image/SDL_image.h>

#include "window.h"

using namespace std;

int main()
{
    Window* window = new Window;
    
    cout << "Started" << endl;
    
    delete window;
    
    return 0;
}