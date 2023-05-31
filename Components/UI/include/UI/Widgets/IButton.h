#pragma once

#include "IWigdet.h"
#include <string>

enum class ButtonType
{
    PushButton,
    CheckBox
};

class IButton : public IWidget
{
public:
    IButton(WORD id, const std::string &name, const Size &size, const Position &position, const Text &text) : IWidget(id, name, size, position, text) {}
    virtual ButtonType getButtonType() = 0;

protected:
    std::string getClassName() override
    {
        return "Button";
    }

private:
};