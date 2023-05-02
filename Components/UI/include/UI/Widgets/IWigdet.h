#pragma once
#ifndef UNICODE
#define UNICODE
#endif

#include <windows.h>

class IWidget
{
protected:
    HWND _hwnd;
    virtual bool create() = 0;

public:
    IWidget() : _hwnd(NULL) {}
    HWND get_hwnd() const { return _hwnd; }
};