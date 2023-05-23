#include "UI/Widgets/LineEdit.h"

LineEdit::LineEdit(WORD id, const Size &size, int x, int y, const Text &text)
    : IWidget(id, size, text), _x{x}, _y{y}
{
}

bool LineEdit::render(HWND parent)
{
    _hwnd = CreateWindowEx(
        0,                                                  // Extended window style (0 for default)
        _className.c_str(),                                 // Control class name
        _text.getText().c_str(),                            // Control text (empty for now)
        WS_CHILD | WS_VISIBLE | WS_BORDER | ES_AUTOHSCROLL, // Control style
        _x,                                                 // Control x-position
        _y,                                                 // Control y-position
        _size.getWidth(),                                   // Control width
        _size.getHeight(),                                  // Control height
        parent,                                             // Parent window or dialog handle
        (HMENU)_id,                                         // Control identifier
        GetModuleHandle(NULL),                              // Instance handle
        NULL                                                // Additional application-specific data (NULL for now)
    );

    SendMessage(_hwnd, WM_SETFONT, (WPARAM)_text.getFont().getHandle(), MAKELPARAM(TRUE, 0));
    return (_hwnd ? TRUE : FALSE);
}