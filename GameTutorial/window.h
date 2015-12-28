#pragma once

class Window
{
public:
    Window();
    ~Window();
    
    int GetWidth() const;
    int GetHeight() const;
private:
    const int mWidth;
    const int mHeight;
};
