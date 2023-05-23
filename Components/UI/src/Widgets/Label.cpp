#include "UI/Widgets/Label.h"

Label::Label(WORD id, const Size &size, const Position &position, const Text &text)
    : IWidget(id, size, position, text)
{
}

int Label::getStyles()
{
    return WS_TABSTOP | WS_VISIBLE | WS_CHILD;
}