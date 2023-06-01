#pragma once

#include "IWigdet.h"
#include <string>
#include <CommCtrl.h>

class Edit : public IWidget
{

public:
    Edit(WORD id, const std::string &name, const Size &size, const Position &position);

    bool render(Window &parent) override;

protected:
    int getExStyle() override;

    std::string getClassName() override;

    int getStyles() override;

public:
    // Event _textChanged;
};

// clickable
class SpinBox : public IWidget
{
public:
    SpinBox(WORD id, const std::string &name, int upperLimit, int lowerLimit, int defaultPosition, WORD editFieldId);

    bool render(Window &parent) override;

protected:
    std::string getClassName() override;

    int getStyles() override;

private:
    int _upperLimit;
    int _lowerLimit;
    int _defaultPos;
    WORD _editFieldId;
    HWND _edit;
};