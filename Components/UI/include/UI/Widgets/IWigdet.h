#pragma once

#include "../Text.h"
#include "../Size.h"
#include "../Position.h"

#include <windows.h>

class Window;

class IWidget
{
protected:
    HWND _hwnd;
    WORD _id;
    std::string _name;
    Size _size;
    Position _position;
    Text _text;

    virtual std::string getClassName() = 0;
    virtual int getStyles() = 0;
    virtual int getExStyle();

public:
    virtual bool render(Window &parent);

    std::string getText()
    {
        int length = GetWindowTextLengthW(_hwnd);
        if (length == 0)
            return "";

        // Allocate memory for the text
        char *buffer = new char[length + 1];

        // Retrieve the text of the static control
        GetWindowText(_hwnd, buffer, length + 1);

        // Convert to wstring
        std::string text(buffer);

        // Clean up and return the text
        delete[] buffer;
        return text;
    }

    int getId()
    {
        return _id;
    }

    std::string getName() const
    {
        return _name;
    }

    void setText(const std::string &text)
    {
        SetWindowText(_hwnd, text.c_str());
    }

    IWidget(WORD id, const std::string &name, const Size &size, const Position &position, const Text &text) : _hwnd(NULL), _id{id}, _name{name}, _size{size}, _position{position}, _text{text} {}
    virtual ~IWidget() = default;
    HWND get_hwnd() const { return _hwnd; }
};