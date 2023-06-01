#pragma once

#include "IButton.h"
#include "../Event.h"
#include <string>

class CheckBox : public IButton
{
public:
    CheckBox(WORD id, const std::string &name, const Size &size, const Position &position, const Text &text, bool clickable);

    bool isChecked() const
    {
        return (SendMessage(_hwnd, BM_GETCHECK, 0, 0) == BST_CHECKED);
    }

    ButtonType getButtonType() override
    {
        return ButtonType::CheckBox;
    }

protected:
    int getStyles() override;

private:
    void changeState()
    {
        SendMessage(_hwnd, BM_SETCHECK, (isChecked() ? BST_UNCHECKED : BST_CHECKED), 0);
    }

private:
public:
};