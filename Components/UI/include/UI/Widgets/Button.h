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
    Button(WORD id, const Text &text, int x, int y, int height, int width);

    bool render(HWND parent) override;

    ButtonType getButtonType() override
    {
        return ButtonType::PushButton;
    }

private:
    std::wstring _className = L"Button";
    int _x;
    int _y;
    int _height;
    int _width;

public:
    Event _click;
    Event _doubleClick;
};