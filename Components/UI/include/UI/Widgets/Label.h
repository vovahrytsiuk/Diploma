#pragma once
#ifndef UNICODE
#define UNICODE
#endif

#include "IWigdet.h"
#include <string>

class Label : public IWidget
{
public:
    Label(WORD id, const Size &size, const Text &text, int x, int y);

public:
    bool render(HWND parent) override;

private:
    std::wstring _className = L"Static";
    int _x;
    int _y;
};