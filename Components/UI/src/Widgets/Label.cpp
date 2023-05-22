#include "UI/Widgets/Label.h"

Label::Label(WORD id, const std::wstring &text, int x, int y, int height, int width)
    : IWidget(id), _text{text}, _x{x}, _y{y}, _height{height}, _width{width}
{
}

bool Label::render(HWND parent)
{
    _hwnd = CreateWindow(
        _className.c_str(),                                    // Predefined class; Unicode assumed
        PCWSTR(_text.c_str()),                                 // Button text
        WS_TABSTOP | WS_VISIBLE | WS_CHILD | BS_DEFPUSHBUTTON, // Styles
        _x,                                                    // x position
        _y,                                                    // y position
        _width,                                                // Button width
        _height,                                               // Button height
        parent,                                                // Parent window
        // (HMENU)params.get_mID(),                               // No menu.
        // NULL,
        (HMENU)_id,
        (HINSTANCE)GetWindowLongPtr(parent, GWLP_HINSTANCE),
        NULL); // Pointer not needed.
    return (_hwnd ? TRUE : FALSE);
}