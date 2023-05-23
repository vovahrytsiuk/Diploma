#ifndef UNICODE
#define UNICODE
#endif

#include "IWigdet.h"
#include "../Event.h"
#include <string>

class LineEdit : public IWidget
{
public:
    LineEdit(WORD id, const Size &size, int x, int y, const Text &text = Text());

public:
    bool render(HWND parent) override;

    // void textChanged()
    // {
    //     std::wstring message = L"LineEdit with id = " + std::to_wstring(_id) + L" text changer";
    //     int msgboxID = MessageBox(
    //         NULL,
    //         message.data(),
    //         (LPCWSTR)L"textChanged() called",
    //         MB_ICONWARNING | MB_CANCELTRYCONTINUE | MB_DEFBUTTON2);

    //     switch (msgboxID)
    //     {
    //     case IDCANCEL:
    //         // TODO: add code
    //         break;
    //     case IDTRYAGAIN:
    //         // TODO: add code
    //         break;
    //     case IDCONTINUE:
    //         // TODO: add code
    //         break;
    //     }
    // }

private:
    std::wstring _className = L"EDIT";
    int _x;
    int _y;

public:
    Event _textChanged;
};