#pragma once
#ifndef UNICODE
#define UNICODE
#endif


#include <windows.h>

class Window
{
public:
    LPCWSTR  ClassName() const { return L"Main Window"; }
    Window([[maybe_unused]] HINSTANCE hInstance, [[maybe_unused]] HINSTANCE hPrevInstance, [[maybe_unused]] PWSTR pCmdLine, [[maybe_unused]] int nCmdShow)
    {
         

        WNDCLASS wc = {};

        wc.lpfnWndProc = Window::WindowProc;
        wc.hInstance = hInstance;
        wc.lpszClassName = ClassName();

        RegisterClass(&wc);

        // Create the window.

        _hwnd = CreateWindowEx(
            0,                           // Optional window styles.
            ClassName(),                  // Window class
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
    static LRESULT CALLBACK WindowProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam)
    {
        switch (uMsg)
        {
        case WM_DESTROY:
            PostQuitMessage(0);
            return 0;

        case WM_PAINT:
        {
            PAINTSTRUCT ps;
            HDC hdc = BeginPaint(hwnd, &ps);

            // All painting occurs here, between BeginPaint and EndPaint.

            FillRect(hdc, &ps.rcPaint, (HBRUSH)(COLOR_WINDOW + 1));

            EndPaint(hwnd, &ps);
        }
            return 0;
        }
        return DefWindowProc(hwnd, uMsg, wParam, lParam);
    }

    HWND _hwnd;
};