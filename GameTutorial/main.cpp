#include "window.h"

int main()
{
    Window* window = new Window("Game 640x480", 680, 480);
    window->Init();
    window->Loop();
    
    delete window;
    
    return 0;
}