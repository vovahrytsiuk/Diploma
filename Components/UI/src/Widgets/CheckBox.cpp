#include "UI/Widgets/CheckBox.h"

CheckBox::CheckBox(WORD id, const std::string &name, const Size &size, const Position &position, const Text &text, bool clickable)
    : IButton(id, name, size, position, text, clickable)
{
    _click.connect([this]()
                   { this->changeState(); });
}

int CheckBox::getStyles()
{
    return WS_CHILD | WS_VISIBLE | BS_CHECKBOX | WS_BORDER;
}
