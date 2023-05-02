#include "UI/Widgets/Button.h"

Button::Button(const std::wstring &text, int x, int y, int height, int width, HWND parent)
    : _text{text}, _x{x}, _y{y}, _height{height}, _width{width}, _parent{parent}
{
    create();
}

bool Button::create()
{
    _hwnd = CreateWindow(
        _className.c_str(),                                    // Predefined class; Unicode assumed
        PCWSTR(_text.c_str()),                                 // Button text
        WS_TABSTOP | WS_VISIBLE | WS_CHILD | BS_DEFPUSHBUTTON, // Styles
        _x,                                                    // x position
        _y,                                                    // y position
        _width,                                                // Button width
        _height,                                               // Button height
        _parent,                                               // Parent window
        // (HMENU)params.get_mID(),                               // No menu.
        NULL,
        (HINSTANCE)GetWindowLongPtr(_parent, GWLP_HINSTANCE),
        NULL); // Pointer not needed.
    return (_hwnd ? TRUE : FALSE);
}