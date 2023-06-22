#pragma once

#include "IButton.h"
#include "../Event.h"
#include <string>

class Button : public IButton
{
public:
    Button(WORD id, const std::string &name, const Size &size, const Position &position, const Text &text, bool clickable, bool doubleClickable);

    ButtonType getButtonType() override
    {
        return ButtonType::PushButton;
    }

    bool getDoubleClickable() const
    {
        return _doubleClickable;
    }

    void setDoubleClickable(bool doubleClickable)
    {
        _doubleClickable = doubleClickable;
    }

private:
    bool _doubleClickable;

protected:
    int getStyles() override;

public:
    Event _doubleClick;
};