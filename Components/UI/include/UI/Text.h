#pragma once
#ifndef UNICODE
#define UNICODE
#endif

#include "Font.h"
#include <string>

class Text final
{
public:
    Text(const std::wstring &text = L"", const Font &font = Font())
        : _text{text}, _font(font)
    {
    }

    auto &getText()
    {
        return _text;
    }

    auto &getFont()
    {
        return _font;
    }

private:
    std::wstring _text;
    Font _font;
};