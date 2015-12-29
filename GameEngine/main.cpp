#include "window.h"

int main()
{    
    Window& window = Window::GetInstance();
    
    if (window.Init())
    {
        if (window.LoadBackground())
        {
            window.Loop();
        }
    }
    
    window.Free();
    
    return 0;
}