#pragma once

#include "Widgets/IWigdet.h"
#include <memory>
#include "Widgets/Button.h"

#include <windows.h>
#include <string>
#include <vector>
#include <unordered_map>
#include <stdexcept>

class Window
{
public:
    Window(){};
    Window(const std::string &title, const Size &size, HINSTANCE hInstance)
        : _title{title}, _size{size}, _hInstance{hInstance}, _isShown{true}
    {
        WNDCLASS wc = {};

        wc.lpfnWndProc = Window::WindowProc;
        wc.hInstance = hInstance;
        wc.lpszClassName = _className.c_str();

        RegisterClass(&wc);
    }

    template <class Widget, typename... Args>
    WORD addWidget(const std::string &name, Args... args)
    {
        WORD id = static_cast<WORD>(_widgets.size());
        _widgets[id] = (std::make_unique<Widget>(id, name, args...));
        _widgetNameToId[name] = id;
        return id;
    }

    template <class Widget>
    Widget *findWidgetById(WORD id)
    {
        if (_widgets.count(id))
        {
            return dynamic_cast<Widget *>(_widgets.at(id).get());
        }
        return nullptr;
    }

    template <class Widget>
    Widget *findWidgetByName(const std::string &name)
    {
        if (_widgetNameToId.count(name))
        {
            return findWidgetById<Widget>(_widgetNameToId[name]);
        }
        return nullptr;
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
        for (const auto &[key, value] : _widgets)
        {
            if (!value->render(*this))
            {
                throw std::runtime_error("Widget with name =\"" + value.get()->getName() + "\" not rendered");
            }
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
            CW_USEDEFAULT, CW_USEDEFAULT,
            _size.getWidth(), _size.getHeight(),

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

    void SetTitle(const std::string &title)
    {
        _title = title;
        SetWindowText(_hwnd, _title.c_str());
    }

    HWND getHandle()
    {
        return _hwnd;
    }

    auto getHinstance()
    {
        return _hInstance;
    }

private:
    template <class Widget>
    Widget *defineWidget(WORD id)
    {
        auto &widget = _widgets[id];
        return dynamic_cast<Widget *>(widget.get());
    }

private:
    std::string _className = "Window";

    std::string _title;
    Size _size;
    bool _isShown;
    HINSTANCE _hInstance;
    HWND _hwnd;

    std::unordered_map<WORD, std::unique_ptr<IWidget>> _widgets;
    std::unordered_map<std::string, WORD> _widgetNameToId;

    static LRESULT CALLBACK WindowProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam);
};