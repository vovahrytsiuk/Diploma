#pragma once
#ifndef UNICODE
#define UNICODE
#endif

#include <windows.h>
#include <string>

class Window
{
public:
    Window([[maybe_unused]] HINSTANCE hInstance, [[maybe_unused]] int nCmdShow)
    {

        WNDCLASS wc = {};

        wc.lpfnWndProc = Window::WindowProc;
        wc.hInstance = hInstance;
        wc.lpszClassName = _className.c_str();

        RegisterClass(&wc);

        // Create the window.

        _hwnd = CreateWindowEx(
            0,                           // Optional window styles.
            _className.c_str(),          // Window class
            L"Learn to Program Windows", // Window text
            WS_OVERLAPPEDWINDOW,         // Window style

            // Size and position
            CW_USEDEFAULT, CW_USEDEFAULT, CW_USEDEFAULT, CW_USEDEFAULT,

            NULL,      // Parent window
            NULL,      // Menu
            hInstance, // Instance handle
            NULL       // Additional application data
        );

        ShowWindow(_hwnd, nCmdShow);

        // Run the message loop.

        MSG msg = {};
        while (GetMessage(&msg, NULL, 0, 0) > 0)
        {
            TranslateMessage(&msg);
            DispatchMessage(&msg);
        }
    }

private:
    std::wstring _className = L"Main Window";
    static LRESULT CALLBACK WindowProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam);

    HWND _hwnd;
};