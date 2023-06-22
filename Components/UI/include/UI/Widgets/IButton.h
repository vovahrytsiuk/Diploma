#pragma once

#include "IWigdet.h"
#include "../Event.h"
#include <string>

enum class ButtonType
{
    PushButton,
    CheckBox,
    RadioButton
};

class IButton : public IWidget
{
public:
    IButton(WORD id, const std::string &name, const Size &size, const Position &position, const Text &text, bool clickable) : IWidget(id, name, size, position, text), _clickable{clickable} {}
    virtual ButtonType getButtonType() = 0;

    bool getClickable() const
    {
        return _clickable;
    }

    void setClickable(bool clickable)
    {
        _clickable = clickable;
    }

    Event _click;

protected:
    std::string getClassName() override
    {
        return "Button";
    }

private:
    bool _clickable;
};