#pragma once
#ifndef UNICODE
#define UNICODE
#endif

#include "IWigdet.h"
#include <CommCtrl.h>
#include <string>

class Window;

class TrackBar : public IWidget
{
public:
    TrackBar(WORD id, const Size &size, const Position &position, const Text &text);

    bool render(Window &parent) override;

protected:
    std::wstring getClassName() override
    {
        return TRACKBAR_CLASS;
    }

    int getStyles() override;

private:
    std::wstring _className = L"Static";
};