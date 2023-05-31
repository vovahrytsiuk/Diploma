#include "UI/Widgets/Button.h"

Button::Button(WORD id, const std::string &name, const Size &size, const Position &position, const Text &text)
    : IButton(id, name, size, position, text)
{
}

int Button::getStyles()
{
    return WS_TABSTOP | WS_VISIBLE | WS_CHILD | BS_DEFPUSHBUTTON | BS_NOTIFY;
}