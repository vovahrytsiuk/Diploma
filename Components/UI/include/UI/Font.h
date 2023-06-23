#pragma once

#include <Windows.h>
#include <string>

class Font
{
public:
    Font(int height = 18, bool bold = false, bool italic = false, bool underline = false, bool strikeOut = false, const std::string &faceName = "Calibri")
        : _height{height}, _bold{bold}, _italic{italic}, _underline{underline}, _strikeOut{strikeOut}, _handle{NULL}, _faceName{faceName}
    {
    }

    Font(const Font &font)
    {
        _height = font._height;
        _italic = font._italic;
        _underline = font._underline;
        _strikeOut = font._strikeOut;
        _bold = font._bold;
        _faceName = font._faceName;
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
            _handle = CreateFont(_height, 0, 0, 0, (_bold ? FW_BOLD : FW_NORMAL), _italic, _underline, _strikeOut, DEFAULT_CHARSET, OUT_DEFAULT_PRECIS, CLIP_DEFAULT_PRECIS, DEFAULT_QUALITY, DEFAULT_PITCH | FF_DONTCARE, _faceName.c_str());
        }
        return _handle;
    }

    int getHeight() const
    {
        return _height;
    }

    void setHeight(int height)
    {
        _height = height;
    }

    bool getItalic() const
    {
        return _italic;
    }

    bool setItalic(bool italic)
    {
        _italic = italic;
    }

    bool getUnderline() const
    {
        return _underline;
    }

    void setUnderline(bool underline)
    {
        _underline = underline;
    }

    bool getBold() const
    {
        return _bold;
    }

    void setBold(bool bold)
    {
        _bold = bold;
    }

    bool getStrikeOut() const
    {
        return _strikeOut;
    }

    void setStrikeOut(bool strikeOut)
    {
        _strikeOut = strikeOut;
    }

    std::string getFaceName() const
    {
        return _faceName;
    }

    void setFaceName(const std::string &faceName)
    {
        _faceName = faceName;
    }

private:
    int _height;
    bool _bold;
    bool _italic;
    bool _underline;
    bool _strikeOut;
    HFONT _handle;
    std::string _faceName;
};