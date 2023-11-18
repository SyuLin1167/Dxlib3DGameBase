#include "Window.h"

std::unique_ptr<Window> Window::singleton = nullptr;

void Window::Init()
{
    if (!singleton)
    {
        singleton.reset(new Window);
    }
}

Window::Window()
{
    //�E�B���h�E�̐ݒ�
    ChangeWindowMode(true);
    SetGraphMode(static_cast<int>(WINDOW_SIZE.x), static_cast<int>(WINDOW_SIZE.y), COLOR_BIT);
    SetWindowSizeExtendRate(1.0);
    SetMainWindowText("Pass&Over");
}

Window::~Window()
{
    //�����Ȃ�
}