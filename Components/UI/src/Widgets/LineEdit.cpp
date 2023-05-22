#include "UI/Widgets/LineEdit.h"

LineEdit::LineEdit(WORD id, int x, int y, int height, int width)
    : IWidget(id), _x{x}, _y{y}, _height{height}, _width{width}
{
}

bool LineEdit::render(HWND parent)
{
    _hwnd = CreateWindowEx(
        0,                                                  // Extended window style (0 for default)
        _className.c_str(),                                 // Control class name
        NULL,                                               // Control text (empty for now)
        WS_CHILD | WS_VISIBLE | WS_BORDER | ES_AUTOHSCROLL, // Control style
        _x,                                                 // Control x-position
        _y,                                                 // Control y-position
        _width,                                             // Control width
        _height,                                            // Control height
        parent,                                             // Parent window or dialog handle
        (HMENU)_id,                                         // Control identifier
        GetModuleHandle(NULL),                              // Instance handle
        NULL                                                // Additional application-specific data (NULL for now)
    );
    return (_hwnd ? TRUE : FALSE);
}