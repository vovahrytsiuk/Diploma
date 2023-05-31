#pragma once

#include "IButton.h"
#include "../Event.h"
#include <string>

class Button : public IButton
{
public:
    Button(WORD id, const std::string &name, const Size &size, const Position &position, const Text &text);

    ButtonType getButtonType() override
    {
        return ButtonType::PushButton;
    }

protected:
    int getStyles() override;

public:
    Event _click;
    Event _doubleClick;
};