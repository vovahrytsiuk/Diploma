#include <UI/Widgets/IWigdet.h>
#include <UI/Window.h>

bool IWidget::render(Window &parent)
{
    _hwnd = CreateWindowEx(
        getExStyle(),
        getClassName().c_str(),  // Predefined class; Unicode assumed
        _text.getText().c_str(), // Text
        getStyles(),             // Styles
        _position.getX(),        // x position
        _position.getY(),        // y position
        _size.getWidth(),        // Width
        _size.getHeight(),       // Height
        parent.getHandle(),      // Parent window
        (HMENU)_id,              // No menu.
        (HINSTANCE)GetWindowLongPtr(parent.getHandle(), GWLP_HINSTANCE),
        NULL); // Pointer not needed.

    SendMessage(_hwnd, WM_SETFONT, (WPARAM)_text.getFont().getHandle(), MAKELPARAM(TRUE, 0));

    return _hwnd != NULL;
}

int IWidget::getExStyle()
{
    return 0;
}