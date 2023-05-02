#ifndef UNICODE
#define UNICODE
#endif

#include "IWigdet.h"
#include <string>

class Button : public IWidget
{
public:
    Button(const std::wstring &text, int x, int y, int height, int width, HWND parent);

protected:
    bool create() override;

private:
    std::wstring _className = L"Button";
    std::wstring _text;
    int _x;
    int _y;
    int _height;
    int _width;
    HWND _parent;
};