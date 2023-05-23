#pragma once
#ifndef UNICODE
#define UNICODE
#endif

#include "IButton.h"
#include "../Event.h"
#include <string>

class Button : public IButton
{
public:
    Button(WORD id, const Size &size, const Text &text, int x, int y);

    bool render(HWND parent) override;

    ButtonType getButtonType() override
    {
        return ButtonType::PushButton;
    }

private:
    std::wstring _className = L"Button";
    int _x;
    int _y;

public:
    Event _click;
    Event _doubleClick;
};