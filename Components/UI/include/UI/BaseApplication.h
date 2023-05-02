#pragma once
#ifndef UNICODE
#define UNICODE
#endif

#include "Window.h"
#include <string>
#include "Widgets/Button.h"
#include "Widgets/Label.h"

class BaseApplication
{
public:
    BaseApplication(std::wstring title)
        : _hInstance{GetModuleHandle(NULL)}, _mainWindow{title, _hInstance}, _button{L"It's button", 10, 10, 50, 150, _mainWindow.getHandle()}, _label{L"It's label", 100, 100, 50, 150, _mainWindow.getHandle()}
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
    Button _button;
    Label _label;
};