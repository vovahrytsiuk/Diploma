#include "UI/Widgets/Button.h"

Button::Button(WORD id, const std::wstring &text, int x, int y, int height, int width)
    : IButton(id), _text{text}, _x{x}, _y{y}, _height{height}, _width{width}
{
}

bool Button::render(HWND parent)
{
    _hwnd = CreateWindow(
        _className.c_str(),                                                // Predefined class; Unicode assumed
        PCWSTR(_text.c_str()),                                             // Button text
        WS_TABSTOP | WS_VISIBLE | WS_CHILD | BS_DEFPUSHBUTTON | BS_NOTIFY, // Styles
        _x,                                                                // x position
        _y,                                                                // y position
        _width,                                                            // Button width
        _height,                                                           // Button height
        parent,                                                            // Parent window
        (HMENU)_id,                                                        // No menu.
        // NULL,
        (HINSTANCE)GetWindowLongPtr(parent, GWLP_HINSTANCE),
        NULL); // Pointer not needed.

    SetWindowLongPtr(_hwnd, GWLP_USERDATA, reinterpret_cast<LONG_PTR>(this));

    // Set the new font for the button
    SendMessage(_hwnd, WM_SETFONT, (WPARAM)_font.getHandle(), MAKELPARAM(TRUE, 0));

    return (_hwnd ? TRUE : FALSE);
}