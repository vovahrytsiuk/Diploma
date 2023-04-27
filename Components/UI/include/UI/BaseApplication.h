#pragma once
#ifndef UNICODE
#define UNICODE
#endif

#include "Window.h"

class BaseApplication
{
public:
    BaseApplication([[maybe_unused]] HINSTANCE hInstance, [[maybe_unused]] HINSTANCE hPrevInstance, [[maybe_unused]] PWSTR pCmdLine, [[maybe_unused]] int nCmdShow)
        : _hInstance{hInstance}, _hPrevInstance{hPrevInstance}, _pCmdLine{pCmdLine}, _nCmdShow{nCmdShow}, _mainWindow{_hInstance, _nCmdShow}
    {
    }

private:
    HINSTANCE _hInstance;
    HINSTANCE _hPrevInstance;
    PWSTR _pCmdLine;
    int _nCmdShow;
    Window _mainWindow;
};