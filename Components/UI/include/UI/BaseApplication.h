#pragma once
#ifndef UNICODE
#define UNICODE
#endif

#include "Window.h"
#include <string>
#include "Widgets/Button.h"
#include "Widgets/Label.h"
#include "Widgets/LineEdit.h"
#include "Widgets/CheckBox.h"
#include "WindowsParamsMock.h"

// clang-format off
WindowParams defaultParams{
    L"Window Title",
    { // button
        {1, L"It's button", 10, 10, 50, 150},
        {2, L"Button 2", 10, 100, 50, 150}
    },
    { // static controls
        {3, L"Label", 10, 200, 50, 150}
    },
    { // line edits
        {4, 250, 250, 50, 150}
    },
    { // check boxes
        {5, L"CheckBox1", 500, 300, 50, 150},
        {6, L"CheckBox2", 500, 500, 50, 150}
    },
};
// clang-format on

class BaseApplication
{
public:
    BaseApplication(const WindowParams &params = defaultParams)
        : _hInstance{GetModuleHandle(NULL)}, _mainWindow{params._title, _hInstance}

    {
        for (const auto &button : params._buttons)
        {
            _mainWindow.addWidget<Button>(button._id, Size(button._height, button._width), Position(button._x, button._y), Text(button._text));
        }

        for (const auto &label : params._labels)
        {
            _mainWindow.addWidget<Label>(label._id, Size(label._height, label._width), Position(label._x, label._y), Text(label._text));
        }

        for (const auto &lineEdit : params._lineEdits)
        {
            _mainWindow.addWidget<LineEdit>(lineEdit._id, Size(lineEdit._height, lineEdit._width), Position(lineEdit._x, lineEdit._y));
        }

        for (const auto &checkBox : params._checkBoxes)
        {
            _mainWindow.addWidget<CheckBox>(checkBox._id, Size(checkBox._height, checkBox._width), Position(checkBox._x, checkBox._y), Text(checkBox._text));
        }

        _mainWindow.render();
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