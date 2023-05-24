#pragma once
#ifndef UNICODE
#define UNICODE
#endif

#include "../Text.h"
#include "../Size.h"
#include "../Position.h"

#include <windows.h>

class IWidget
{
protected:
    HWND _hwnd;
    WORD _id;
    Size _size;
    Position _position;
    Text _text;

    virtual std::wstring getClassName() = 0;
    virtual int getStyles() = 0;

public:
    virtual bool render(HWND parent)
    {
        _hwnd = CreateWindowEx(
            0,
            getClassName().c_str(),          // Predefined class; Unicode assumed
            PCWSTR(_text.getText().c_str()), // Text
            getStyles(),                     // Styles
            _position.getX(),                // x position
            _position.getY(),                // y position
            _size.getWidth(),                // Width
            _size.getHeight(),               // Height
            parent,                          // Parent window
            (HMENU)_id,                      // No menu.
            (HINSTANCE)GetWindowLongPtr(parent, GWLP_HINSTANCE),
            NULL); // Pointer not needed.

        SendMessage(_hwnd, WM_SETFONT, (WPARAM)_text.getFont().getHandle(), MAKELPARAM(TRUE, 0));

        return _hwnd != NULL;
    }

    std::wstring getText()
    {
        int length = GetWindowTextLengthW(_hwnd);
        if (length == 0)
            return L"";

        // Allocate memory for the text
        wchar_t *buffer = new wchar_t[length + 1];

        // Retrieve the text of the static control
        GetWindowTextW(_hwnd, buffer, length + 1);

        // Convert to wstring
        std::wstring text(buffer);

        // Clean up and return the text
        delete[] buffer;
        return text;
    }

    int getId()
    {
        return _id;
    }

    void setText(const std::wstring &text)
    {
        SetWindowText(_hwnd, text.c_str());
    }

    IWidget(WORD id, const Size &size, const Position &position, const Text &text) : _hwnd(NULL), _id{id}, _size{size}, _position{position}, _text{text} {}
    virtual ~IWidget() = default;
    HWND get_hwnd() const { return _hwnd; }
};