#include "UI/Widgets/TrackBar.h"
#include <UI/Window.h>

TrackBar::TrackBar(WORD id, const Size &size, const Position &position, const Text &text)
    : IWidget(id, size, position, text)
{
}

int TrackBar::getStyles()
{
    return WS_CHILD |
           WS_VISIBLE |
           TBS_AUTOTICKS |
           TBS_ENABLESELRANGE;
}

bool TrackBar::render(Window &parent)
{
    int iMin = 10;
    int iMax = 100;
    int iSelMin = 20;
    int iSelMax = 80;
    IWidget::render(parent);
    SendMessage(_hwnd, TBM_SETRANGE,
                (WPARAM)TRUE,                  // redraw flag
                (LPARAM)MAKELONG(iMin, iMax)); // min. & max. positions

    SendMessage(_hwnd, TBM_SETPAGESIZE,
                0, (LPARAM)4); // new page size

    SendMessage(_hwnd, TBM_SETSEL,
                (WPARAM)FALSE, // redraw flag
                (LPARAM)MAKELONG(iSelMin, iSelMax));

    SendMessage(_hwnd, TBM_SETPOS,
                (WPARAM)TRUE, // redraw flag
                (LPARAM)iSelMin);

    SetFocus(_hwnd);

    return _hwnd != NULL;
}