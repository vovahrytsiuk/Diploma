#include "UI/Widgets/CheckBox.h"

CheckBox::CheckBox(WORD id, const Size &size, const Position &position, const Text &text)
    : IButton(id, size, position, text)
{
    _stateChanged.connect([this]()
                          { this->changeState(); });
}

int CheckBox::getStyles()
{
    return WS_CHILD | WS_VISIBLE | BS_CHECKBOX;
}
