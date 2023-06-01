#pragma once

#include "IButton.h"
#include "../Event.h"
#include <string>

class RadioButton : public IButton
{
public:
    RadioButton(WORD id, const std::string &name, const Size &size, const Position &position, const Text &text, bool clickable, bool newGroup);

    ButtonType getButtonType() override
    {
        return ButtonType::RadioButton;
    }

protected:
    int getStyles() override;

private:
private:
    bool _newGroup;
};