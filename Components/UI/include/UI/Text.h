#pragma once

#include "Font.h"
#include <string>

class Text final
{
public:
    Text(const std::string &text = "", const Font &font = Font())
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
    std::string _text;
    Font _font;
};