#include <UI/Window.h>
#include <UI/Widgets/Button.h>
#include <UI/Widgets/CheckBox.h>
#include <UI/Widgets/FieldEdit.h>

LRESULT CALLBACK Window::WindowProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam)
{
    Window *pThis = NULL;
    if (uMsg == WM_NCCREATE)
    {
    }
    else
    {
        pThis = (Window *)GetWindowLongPtr(hwnd, GWLP_USERDATA);
    }

    if (pThis)
    {
        switch (uMsg)
        {
        case WM_DESTROY:
            PostQuitMessage(0);
            return 0;

        case WM_PAINT:
        {
            PAINTSTRUCT ps;
            HDC hdc = BeginPaint(hwnd, &ps);

            // All painting occurs here, between BeginPaint and EndPaint.

            FillRect(hdc, &ps.rcPaint, (HBRUSH)(COLOR_WINDOW + 1));

            EndPaint(hwnd, &ps);
            return 0;
        }
        case WM_COMMAND:
            switch (HIWORD(wParam))
            {
            case BN_CLICKED:
            {
                auto *button = pThis->defineWidget<IButton>(LOWORD(wParam));
                if (button && button->getClickable())
                {
                    button->_click.emit();
                }
                break;
            }
            case BN_DBLCLK:
            {
                auto *button = pThis->defineWidget<Button>(LOWORD(wParam));
                if (button && button->getDoubleClickable())
                {
                    button->_doubleClick.emit();
                }
                break;
            }
            case EN_CHANGE:
            {
                auto *lineEdit = pThis->defineWidget<FieldEdit>(LOWORD(wParam));
                if (lineEdit)
                {
                    lineEdit->_textChanged.emit();
                }
                break;
            }
            }
            return 0;
        }
    }

    return DefWindowProc(hwnd, uMsg, wParam, lParam);
}