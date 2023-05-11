#ifndef UNICODE
#define UNICODE
#endif

#include "IWigdet.h"
#include <string>

class Button : public IWidget
{
public:
    Button(const std::wstring &text, int x, int y, int height, int width);

    bool render(HWND parent) override;

    void click()
    {
        int msgboxID = MessageBox(
            NULL,
            (LPCWSTR)L"Button clicked",
            (LPCWSTR)L"click() called",
            MB_ICONWARNING | MB_CANCELTRYCONTINUE | MB_DEFBUTTON2);

        switch (msgboxID)
        {
        case IDCANCEL:
            // TODO: add code
            break;
        case IDTRYAGAIN:
            // TODO: add code
            break;
        case IDCONTINUE:
            // TODO: add code
            break;
        }
    }

    // static LRESULT CALLBACK WndProc(HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam)
    // {
    //     Button *button = reinterpret_cast<Button *>(GetWindowLongPtr(hWnd, GWLP_USERDATA));
    //     switch (uMsg)
    //     {
    //     case WM_COMMAND:
    //         if (HIWORD(wParam) == BN_CLICKED && button)
    //         {
    //             button->click();
    //         }
    //         break;
    //     default:
    //         return DefWindowProc(hWnd, uMsg, wParam, lParam);
    //     }
    //     return 0;
    // }

private:
    std::wstring _className = L"Button";
    std::wstring _text;
    int _x;
    int _y;
    int _height;
    int _width;
    HWND _parent;
};