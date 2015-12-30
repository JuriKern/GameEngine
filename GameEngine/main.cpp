#include "window.h"

int main()
{    
    Window* window = Window::GetInstance();
    
    if (window->Init())
    {
        if (window->LoadBackground())
        {
            window->Loop();
        }
    }
    
    window = nullptr;
    
    return 0;
}