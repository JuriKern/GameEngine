#include "window.h"

int main()
{    
    Window* window = new Window("Game 1280x960", 1280, 960);
    
    if (window->Init())
    {
        if (window->LoadBackground())
        {
            window->Loop();
        }
    }
    
    delete window;
    
    return 0;
}