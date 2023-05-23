#pragma once
#ifndef UNICODE
#define UNICODE
#endif

#include "IButton.h"
#include "../Event.h"
#include <string>

class CheckBox : public IButton
{
public:
    CheckBox(WORD id, const Text &text, int x, int y, int height, int width);

    bool render(HWND parent) override;

    bool isChecked() const
    {
        return (SendMessage(_hwnd, BM_GETCHECK, 0, 0) == BST_CHECKED);
    }

    ButtonType getButtonType() override
    {
        return ButtonType::CheckBox;
    }

private:
    void changeState()
    {
        SendMessage(_hwnd, BM_SETCHECK, (isChecked() ? BST_UNCHECKED : BST_CHECKED), 0);
    }

private:
    std::wstring _className = L"Button";
    int _x;
    int _y;
    int _height;
    int _width;

public:
    Event _stateChanged;
};