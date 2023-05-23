#pragma once
#ifndef UNICODE
#define UNICODE
#endif

#include "IWigdet.h"
#include <string>

class Label : public IWidget
{
public:
    Label(WORD id, const Text &text, int x, int y, int height, int width);

public:
    bool render(HWND parent) override;

private:
    std::wstring _className = L"Static";
    int _x;
    int _y;
    int _height;
    int _width;
};