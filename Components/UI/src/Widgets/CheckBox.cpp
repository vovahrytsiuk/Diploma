#include "UI/Widgets/CheckBox.h"

CheckBox::CheckBox(WORD id, const std::wstring &text, int x, int y, int height, int width)
    : IButton(id), _text{text}, _x{x}, _y{y}, _height{height}, _width{width}
{
}

bool CheckBox::render(HWND parent)
{
    _hwnd = CreateWindow(
        _className.c_str(),                  // Predefined class; Unicode assumed
        PCWSTR(_text.c_str()),               // Button text
        WS_CHILD | WS_VISIBLE | BS_CHECKBOX, // Styles
        _x,                                  // x position
        _y,                                  // y position
        _width,                              // Button width
        _height,                             // Button height
        parent,                              // Parent window
        (HMENU)_id,                          // No menu.
        // NULL,
        (HINSTANCE)GetWindowLongPtr(parent, GWLP_HINSTANCE),
        NULL); // Pointer not needed.

    SetWindowLongPtr(_hwnd, GWLP_USERDATA, reinterpret_cast<LONG_PTR>(this));

    // Get the current font of the button
    HFONT hCurrentFont = (HFONT)SendMessage(_hwnd, WM_GETFONT, 0, 0);

    // Create a new font with the desired characteristics
    HFONT hNewFont = CreateFont(
        20,                          // Height of the font
        0,                           // Width of the font (0 = default)
        0,                           // Angle of escapement (0 = default)
        0,                           // Orientation angle (0 = default)
        1,                           // Font weight
        0,                           // Italic attribute
        0,                           // Underline attribute
        0,                           // Strikeout attribute
        0,                           // Character set identifier
        OUT_DEFAULT_PRECIS,          // Output precision
        CLIP_DEFAULT_PRECIS,         // Clipping precision
        DEFAULT_QUALITY,             // Font quality
        DEFAULT_PITCH | FF_DONTCARE, // Pitch and family
        NULL                         // Font face name
    );

    // Set the new font for the button
    SendMessage(_hwnd, WM_SETFONT, (WPARAM)hNewFont, MAKELPARAM(TRUE, 0));

    // Optionally, delete the old font if it's no longer needed
    if (hCurrentFont != NULL)
        DeleteObject(hCurrentFont);
    return (_hwnd ? TRUE : FALSE);
}