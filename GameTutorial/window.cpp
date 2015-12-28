#include "window.h"

Window::Window() : mWidth(0), mHeight(0) {}

Window::~Window() {}

int Window::GetWidth() const
{
    return mWidth;
}

int Window::GetHeight() const
{
    return mHeight;
}



