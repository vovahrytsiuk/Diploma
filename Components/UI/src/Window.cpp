#include <UI/Window.h>
#include <UI/Widgets/Button.h>

LRESULT CALLBACK Window::WindowProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam)
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

        Button *button = reinterpret_cast<Button *>(GetWindowLongPtr(hwnd, GWLP_USERDATA));

        if (HIWORD(wParam) == BN_CLICKED && button)
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
            button->click();
        }
        break;
    }
    return DefWindowProc(hwnd, uMsg, wParam, lParam);
}