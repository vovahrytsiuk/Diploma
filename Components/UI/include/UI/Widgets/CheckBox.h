#pragma once
#ifndef UNICODE
#define UNICODE
#endif

#include "IButton.h"
#include <string>

class CheckBox : public IButton
{
public:
    CheckBox(WORD id, const std::wstring &text, int x, int y, int height, int width);

    bool render(HWND parent) override;

    ButtonType getButtonType() override
    {
        return ButtonType::CheckBox;
    }

    void stateChanged()
    {
        std::wstring message = L"CheckBox with id = " + std::to_wstring(_id) + L" state changed";
        int msgboxID = MessageBox(
            NULL,
            message.data(),
            (LPCWSTR)L"stateChanged() called",
            MB_ICONWARNING | MB_CANCELTRYCONTINUE | MB_DEFBUTTON2);

        switch (msgboxID)
        {
        case IDCANCEL:
            // TODO: add code
            break;
        case IDTRYAGAIN:
            // TODO: add code
            break;
        case IDCONTINUE:
            // TODO: add code
            break;
        }
    }

private:
    std::wstring _className = L"Button";
    std::wstring _text;
    int _x;
    int _y;
    int _height;
    int _width;
};