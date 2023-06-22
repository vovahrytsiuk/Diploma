#pragma once

#include "IWigdet.h"
#include <string>

class Label : public IWidget
{
public:
    Label(WORD id, const std::string &name, const Size &size, const Position &position, const Text &text);

protected:
    std::string getClassName() override
    {
        return "STATIC";
    }

    int getStyles() override;

private:
};