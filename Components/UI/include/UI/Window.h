#pragma once
#ifndef UNICODE
#define UNICODE
#endif

#include "Widgets/IWigdet.h"
#include <memory>
#include "Widgets/Button.h"

#include <windows.h>
#include <string>
#include <vector>

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
    }

    template <class Widget, typename... Args>
    void addWidget(Args... args)
    {
        _widgets.push_back(std::make_unique<Widget>(WORD(_widgets.size()), args...));
    }

    void render()
    {
        // Render window
        create();
        // Show Window
        show();
        // Render Widgets
        renderWidgets();
    }

    void renderWidgets()
    {
        for (auto &widget : _widgets)
        {
            widget->render(_hwnd);
        }
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

        SetWindowLongPtr(_hwnd, GWLP_USERDATA, (LONG_PTR)this);

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
    template <class Widget>
    Widget *defineWidget(WORD id)
    {
        auto &widget = _widgets[id];
        return dynamic_cast<Widget *>(widget.get());
    }

private:
    std::wstring _className = L"Window";

    std::wstring _title;
    bool _isShown;
    HINSTANCE _hInstance;
    HWND _hwnd;

    std::vector<std::unique_ptr<IWidget>> _widgets;

    static LRESULT CALLBACK WindowProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam);
};