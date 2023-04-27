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
        _mainWindow.SetTitle(L"Hello");
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

private:
    HINSTANCE _hInstance;
    Window _mainWindow;
};