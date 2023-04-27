#pragma once
#ifndef UNICODE
#define UNICODE
#endif

#include <UI/Window.h>

class BaseApplication
{
    BaseApplication([[maybe_unused]] HINSTANCE hInstance, [[maybe_unused]] HINSTANCE hPrevInstance, [[maybe_unused]] PWSTR pCmdLine, [[maybe_unused]] int nCmdShow);
private:
    Window _mainWindow;
};