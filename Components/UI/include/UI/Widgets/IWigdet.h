#pragma once
#ifndef UNICODE
#define UNICODE
#endif

#include "../Text.h"

#include <windows.h>

class IWidget
{
protected:
    HWND _hwnd;
    WORD _id;
    Text _text;

public:
    virtual bool render(HWND parent) = 0;
    IWidget(WORD id, const Text &text) : _hwnd(NULL), _id{id}, _text{text} {}
    virtual ~IWidget() = default;
    HWND get_hwnd() const { return _hwnd; }
};