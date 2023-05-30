#include "UI/Widgets/SpinBox.h"
#include <Commctrl.h>
#include <UI/Window.h>

SpinBox::SpinBox(WORD id, const Size &size, const Position &position, const Text &text, int upperLimit, int lowerLimit, int defaultPosition)
    : IWidget(id, size, position, text), _upperLimit{upperLimit}, _lowerLimit{lowerLimit}, _defaultPos{defaultPosition}
{
}

int SpinBox::getStyles()
{
    return WS_CHILDWINDOW | WS_VISIBLE | UDS_AUTOBUDDY | UDS_SETBUDDYINT | UDS_ALIGNRIGHT | UDS_ARROWKEYS | UDS_HOTTRACK;
}

bool SpinBox::render(Window &parent)
{
    INITCOMMONCONTROLSEX icex;

    icex.dwSize = sizeof(INITCOMMONCONTROLSEX);
    icex.dwICC = ICC_UPDOWN_CLASS;
    InitCommonControlsEx(&icex);

    _hwnd = CreateWindowEx(0, UPDOWN_CLASSW, NULL, WS_CHILD | WS_VISIBLE | UDS_SETBUDDYINT | UDS_ALIGNRIGHT,
                           0, 0, 0, 0, parent.getHandle(), (HMENU)_id, NULL, NULL);
    _edit = CreateWindowExW(WS_EX_CLIENTEDGE, WC_EDITW, NULL, WS_CHILD | WS_VISIBLE | ES_RIGHT, 15, 15, 70, 25, parent.getHandle(),
                            (HMENU)(static_cast<WORD>(_id + 1)), NULL, NULL);

    SendMessageW(_hwnd, UDM_SETBUDDY, (WPARAM)_edit, 0);
    SendMessageW(_hwnd, UDM_SETRANGE, 0, MAKELPARAM(100, 0));
    SendMessageW(_hwnd, UDM_SETPOS32, 0, 0);

    return _hwnd != NULL;
}