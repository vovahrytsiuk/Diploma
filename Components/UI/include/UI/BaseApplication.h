#pragma once
#ifndef UNICODE
#define UNICODE
#endif

#include "Window.h"
#include <string>

class BaseApplication
{
public:
    BaseApplication(std::wstring title)
        : _hInstance{GetModuleHandle(NULL)}, _mainWindow{title, _hInstance}
    {
    }

    void runMessageLoop()
    {
        MSG msg = {};
        while (GetMessage(&msg, NULL, 0, 0) > 0)
        {
            TranslateMessage(&msg);
            DispatchMessage(&msg);
        }
    }

    Window &GetMainWindow()
    {
        return _mainWindow;
    }

private:
    HINSTANCE _hInstance; // Application handle
    Window _mainWindow;   // Main window of the application
};