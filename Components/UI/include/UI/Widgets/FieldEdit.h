#pragma once

#include "IWigdet.h"
#include "../Event.h"
#include <string>

class FieldEdit : public IWidget
{
public:
    FieldEdit(WORD id, const std::string &name, const Size &size, const Position &position, const Text &text = Text(), bool multiline = false);

protected:
    std::string getClassName() override
    {
        return "EDIT";
    }

    int getStyles() override;

public:
    bool _multiline;
    Event _textChanged;
};