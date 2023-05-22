#pragma once
#ifndef UNICODE
#define UNICODE
#endif

#include "IButton.h"
#include <string>

class Button : public IButton
{
public:
    Button(WORD id, const std::wstring &text, int x, int y, int height, int width);

    bool render(HWND parent) override;

    void click()
    {
        std::wstring message = L"Button with id = " + std::to_wstring(_id) + L" clicked";
        int msgboxID = MessageBox(
            NULL,
            message.data(),
            (LPCWSTR)L"click() called",
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

    void doubleClicked()
    {
        std::wstring message = L"Button with id = " + std::to_wstring(_id) + L" double clicked";
        int msgboxID = MessageBox(
            NULL,
            message.data(),
            (LPCWSTR)L"click() called",
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

    ButtonType getButtonType() override
    {
        return ButtonType::PushButton;
    }

private:
    std::wstring _className = L"Button";
    std::wstring _text;
    int _x;
    int _y;
    int _height;
    int _width;
};