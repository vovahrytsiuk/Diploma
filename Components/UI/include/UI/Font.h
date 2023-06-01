#pragma once

#include <Windows.h>
#include <string>

class Font
{
public:
    Font(int height = 18, bool italic = false, bool underline = false, bool strikeOut = false, const std::string &faceName = "Calibri")
        : _height{height}, _italic{italic}, _underline{underline}, _strikeOut{strikeOut}, _handle{NULL}, _faceName{faceName}
    {
    }

    Font(const Font &font)
    {
        _height = font._height;
        _italic = font._italic;
        _underline = font._underline;
        _strikeOut = font._strikeOut;
        _handle = NULL;
    }

    ~Font()
    {
        if (_handle != NULL)
        {
            DeleteObject(_handle);
        }
    }

    auto getHandle()
    {
        if (_handle == NULL)
        {
            _handle = CreateFont(_height, 0, 0, 0, FW_NORMAL, _italic, _underline, _strikeOut, DEFAULT_CHARSET, OUT_DEFAULT_PRECIS, CLIP_DEFAULT_PRECIS, DEFAULT_QUALITY, DEFAULT_PITCH | FF_DONTCARE, _faceName.c_str());
        }
        return _handle;
    }

private:
    int _height;
    bool _italic;
    bool _underline;
    bool _strikeOut;
    HFONT _handle;
    std::string _faceName;
};