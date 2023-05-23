#include "UI/Widgets/LineEdit.h"

LineEdit::LineEdit(WORD id, const Size &size, const Position &position, const Text &text)
    : IWidget(id, size, position, text)
{
}

int LineEdit::getStyles()
{
    return WS_CHILD | WS_VISIBLE | WS_BORDER | ES_AUTOHSCROLL;
}
