#pragma once
#ifndef UNICODE
#define UNICODE
#endif

#include "IWigdet.h"
#include <string>

class Label : public IWidget
{
public:
    Label(WORD id, const Size &size, const Position &position, const Text &text);

protected:
    std::wstring getClassName() override
    {
        return L"STATIC";
    }

    int getStyles() override;

private:
    std::wstring _className = L"Static";
};