#pragma once
#ifndef UNICODE
#define UNICODE
#endif

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
    IButton(WORD id) : IWidget(id) {}
    virtual ButtonType getButtonType() = 0;

private:
};