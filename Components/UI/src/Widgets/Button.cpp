#include "UI/Widgets/Button.h"

Button::Button(WORD id, const std::string &name, const Size &size, const Position &position, const Text &text, bool clickable, bool doubleClickable)
    : IButton(id, name, size, position, text, clickable), _doubleClickable{doubleClickable}
{
}

int Button::getStyles()
{
    return WS_TABSTOP | WS_VISIBLE | WS_CHILD | BS_DEFPUSHBUTTON | BS_NOTIFY;
}