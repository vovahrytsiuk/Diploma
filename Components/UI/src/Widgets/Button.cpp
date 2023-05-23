#include "UI/Widgets/Button.h"

Button::Button(WORD id, const Size &size, const Position &position, const Text &text)
    : IButton(id, size, position, text)
{
}

int Button::getStyles()
{
    return WS_TABSTOP | WS_VISIBLE | WS_CHILD | BS_DEFPUSHBUTTON | BS_NOTIFY;
}