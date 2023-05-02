#pragma once
#ifndef UNICODE
#define UNICODE
#endif

#include <windows.h>
#include <string>

class Window
{
public:
    Window(std::wstring title, HINSTANCE hInstance)
        : _title{title}, _hInstance{hInstance}, _isShown{true}
    {
        WNDCLASS wc = {};

        wc.lpfnWndProc = Window::WindowProc;
        wc.hInstance = hInstance;
        wc.lpszClassName = _className.c_str();

        RegisterClass(&wc);

        create();
        show();
    }

    bool create()
    {
        _hwnd = CreateWindowEx(
            0,                   // Optional window styles.
            _className.c_str(),  // Window class
            _title.c_str(),      // Window text
            WS_OVERLAPPEDWINDOW, // Window style

            // Size and position
            CW_USEDEFAULT, CW_USEDEFAULT, CW_USEDEFAULT, CW_USEDEFAULT,

            NULL,       // Parent window
            NULL,       // Menu
            _hInstance, // Instance handle
            NULL        // Additional application data
        );

        return _hwnd != NULL;
    }

    void show()
    {
        ShowWindow(_hwnd, _isShown);
    }

    void SetTitle(const std::wstring &title)
    {
        _title = title;
        SetWindowText(_hwnd, _title.c_str());
    }

    HWND getHandle()
    {
        return _hwnd;
    }

private:
    std::wstring _className = L"Window";

    std::wstring _title;
    bool _isShown;
    HINSTANCE _hInstance;
    HWND _hwnd;

    static LRESULT CALLBACK WindowProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam);
};