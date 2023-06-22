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

    void setText(const std::string &text)
    {
        _text = text;
    }

    void setFont(const Font &font)
    {
        _font = font;
    }

private:
    std::string _text;
    Font _font;
};