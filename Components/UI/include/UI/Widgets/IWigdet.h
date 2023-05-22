#pragma once
#ifndef UNICODE
#define UNICODE
#endif

#include "../Font.h"

#include <windows.h>

class IWidget
{
protected:
    HWND _hwnd;
    WORD _id;
    Font _font;

public:
    virtual bool render(HWND parent) = 0;
    IWidget(WORD id) : _hwnd(NULL), _id{id} {}
    virtual ~IWidget() = default;
    HWND get_hwnd() const { return _hwnd; }
};