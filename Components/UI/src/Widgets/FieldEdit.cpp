#include "UI/Widgets/FieldEdit.h"

FieldEdit::FieldEdit(WORD id, const std::string &name, const Size &size, const Position &position, const Text &text, bool multiline)
    : IWidget(id, name, size, position, text), _multiline{multiline}
{
}

int FieldEdit::getStyles()
{
    int styles = WS_CHILD | WS_VISIBLE | WS_BORDER | ES_AUTOHSCROLL;
    if (_multiline)
    {
        styles |= WS_VSCROLL |
                  ES_LEFT | ES_MULTILINE | ES_AUTOVSCROLL;
    }
    else
    {
        styles |= ES_AUTOHSCROLL;
    }
    return styles;
}