#ifndef UNICODE
#define UNICODE
#endif

#include "IWigdet.h"
#include "../Event.h"
#include <string>

class FieldEdit : public IWidget
{
public:
    FieldEdit(WORD id, const Size &size, const Position &position, const Text &text = Text());

protected:
    std::wstring getClassName() override
    {
        return L"EDIT";
    }

    int getStyles() override;

public:
    Event _textChanged;
};