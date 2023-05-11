#pragma once
#ifndef UNICODE
#define UNICODE
#endif

#include <windows.h>

class IWidget
{
protected:
    HWND _hwnd;

public:
    virtual bool render(HWND parent) = 0;
    IWidget() : _hwnd(NULL) {}
    HWND get_hwnd() const { return _hwnd; }
};