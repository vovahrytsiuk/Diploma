#include "UI/Widgets/Label.h"

Label::Label(WORD id, const std::string &name, const Size &size, const Position &position, const Text &text)
    : IWidget(id, name, size, position, text)
{
}

int Label::getStyles()
{
    return WS_TABSTOP | WS_VISIBLE | WS_CHILD | SS_CENTER;
}