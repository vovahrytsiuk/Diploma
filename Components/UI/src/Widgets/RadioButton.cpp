#include "UI/Widgets/RadioButton.h"

RadioButton::RadioButton(WORD id, const std::string &name, const Size &size, const Position &position, const Text &text, bool clickable, bool newGroup)
    : IButton(id, name, size, position, text, clickable), _newGroup{newGroup}
{
}

int RadioButton::getStyles()
{
    int styles = WS_CHILD | WS_VISIBLE | BS_AUTORADIOBUTTON;
    if (_newGroup)
    {
        styles |= WS_GROUP;
    }
    return styles;
}
