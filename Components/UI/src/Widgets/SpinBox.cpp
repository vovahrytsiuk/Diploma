#include "UI/Widgets/SpinBox.h"
#include <Commctrl.h>
#include <UI/Window.h>
#include <strsafe.h>

Edit::Edit(WORD id, const std::string &name, const Size &size, const Position &position)
    : IWidget(id, name, size, position, Text())
{
}

std::string Edit::getClassName()
{
    return WC_EDIT;
}

int Edit::getStyles()
{
    return WS_CHILD | WS_VISIBLE | ES_RIGHT | ES_READONLY;
}

int Edit::getExStyle()
{
    return WS_EX_CLIENTEDGE;
}

bool Edit::render(Window &parent)
{
    _hwnd = CreateWindowEx(getExStyle(), getClassName().c_str(), NULL, getStyles(), _position.getX(), _position.getY(), _size.getWidth(), _size.getHeight(), parent.getHandle(),
                           (HMENU)_id, NULL, NULL);
    return _hwnd != NULL;
}

SpinBox::SpinBox(WORD id, const std::string &name, int upperLimit, int lowerLimit, int defaultPosition, WORD editFieldId)
    : IWidget(id, name, Size{0, 0}, Position{0, 0}, Text()), _upperLimit{upperLimit}, _lowerLimit{lowerLimit}, _defaultPos{defaultPosition}, _editFieldId{editFieldId}
{
}

std::string SpinBox::getClassName()
{
    return UPDOWN_CLASS;
}

int SpinBox::getStyles()
{
    return WS_CHILDWINDOW | WS_VISIBLE | UDS_AUTOBUDDY | UDS_SETBUDDYINT | UDS_ALIGNRIGHT | UDS_ARROWKEYS | UDS_HOTTRACK;
}

bool SpinBox::render(Window &parent)
{
    auto *edit = parent.findWidgetById<Edit>(_editFieldId);
    if (edit->get_hwnd())
    {
        INITCOMMONCONTROLSEX icex;

        icex.dwSize = sizeof(INITCOMMONCONTROLSEX);
        icex.dwICC = ICC_UPDOWN_CLASS;
        InitCommonControlsEx(&icex);

        _hwnd = CreateWindow(getClassName().c_str(), NULL, getStyles(),
                             _position.getX(),
                             _position.getY(),
                             _size.getWidth(),
                             _size.getHeight(),
                             parent.getHandle(), (HMENU)_id, NULL, NULL);

        SendMessageW(_hwnd, UDM_SETBUDDY, (WPARAM)(edit->get_hwnd()), 0);
        SendMessageW(_hwnd, UDM_SETRANGE, 0, MAKELPARAM(_upperLimit, _lowerLimit));
        SendMessageW(_hwnd, UDM_SETPOS32, 0, _defaultPos);
    }

    return _hwnd != NULL;
}