#include "UI/Widgets/Button.h"

Button::Button(WORD id, const Size &size, const Text &text, int x, int y)
    : IButton(id, size, text), _x{x}, _y{y}
{
}

bool Button::render(HWND parent)
{
    _hwnd = CreateWindow(
        _className.c_str(),                                                // Predefined class; Unicode assumed
        PCWSTR(_text.getText().c_str()),                                   // Button text
        WS_TABSTOP | WS_VISIBLE | WS_CHILD | BS_DEFPUSHBUTTON | BS_NOTIFY, // Styles
        _x,                                                                // x position
        _y,                                                                // y position
        _size.getWidth(),                                                  // Button width
        _size.getHeight(),                                                 // Button height
        parent,                                                            // Parent window
        (HMENU)_id,                                                        // No menu.
        // NULL,
        (HINSTANCE)GetWindowLongPtr(parent, GWLP_HINSTANCE),
        NULL); // Pointer not needed.

    SetWindowLongPtr(_hwnd, GWLP_USERDATA, reinterpret_cast<LONG_PTR>(this));

    // Set the new font for the button
    SendMessage(_hwnd, WM_SETFONT, (WPARAM)_text.getFont().getHandle(), MAKELPARAM(TRUE, 0));

    return (_hwnd ? TRUE : FALSE);
}