#include "UI/Widgets/FieldEdit.h"

FieldEdit::FieldEdit(WORD id, const Size &size, const Position &position, const Text &text)
    : IWidget(id, size, position, text)
{
}

int FieldEdit::getStyles()
{
    return WS_CHILD | WS_VISIBLE | WS_VSCROLL |
           ES_LEFT | ES_MULTILINE | ES_AUTOVSCROLL | WS_BORDER;
}