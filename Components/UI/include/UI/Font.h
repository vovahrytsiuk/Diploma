#pragma once
#ifndef UNICODE
#define UNICODE
#endif

#include <Windows.h>

class Font
{
public:
    Font(int height = 18, bool italic = false, bool underline = false, bool strikeOut = false)
        : _height{height}, _italic{italic}, _underline{underline}, _strikeOut{strikeOut}, _handle{NULL}
    {
        _handle = CreateFont(_height, 0, 0, 0, FW_NORMAL, _italic, _underline, _strikeOut, DEFAULT_CHARSET, OUT_DEFAULT_PRECIS, CLIP_DEFAULT_PRECIS, DEFAULT_QUALITY, DEFAULT_PITCH | FF_DONTCARE, NULL);
    }

    auto getHandle() const
    {
        return _handle;
    }

private:
    int _height;
    bool _italic;
    bool _underline;
    bool _strikeOut;
    HFONT _handle;
};