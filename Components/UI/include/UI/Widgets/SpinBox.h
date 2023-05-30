#pragma once
#ifndef UNICODE
#define UNICODE
#endif

#include "IWigdet.h"
#include <string>
#include <CommCtrl.h>

class SpinBox : public IWidget
{
public:
    SpinBox(WORD id, const Size &size, const Position &position, const Text &text, int upperLimit, int lowerLimit, int defaultPosition);

    bool render(Window &parent) override;

protected:
    std::wstring getClassName() override
    {
        return UPDOWN_CLASS;
    }

    int getStyles() override;

private:
    int _upperLimit;
    int _lowerLimit;
    int _defaultPos;
    HWND _edit;
};