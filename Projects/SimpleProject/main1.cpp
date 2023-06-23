#include <Windows.h>

int main()
{
    // Get a device context for the window or control
    HDC hdc = GetDC(NULL);

    // Set the text alignment flags
    SetTextAlign(hdc, TA_LEFT | TA_TOP);

    // Set the left and top margins
    int leftMargin = 20;
    int topMargin = 10;

    // Set the text color
    SetTextColor(hdc, RGB(0, 0, 0)); // Black color

    // Set the background color
    SetBkColor(hdc, RGB(255, 255, 255)); // White color

    // Set the text font
    HFONT hFont = CreateFont(16, 0, 0, 0, FW_NORMAL, FALSE, FALSE, FALSE, DEFAULT_CHARSET, OUT_DEFAULT_PRECIS,
                             CLIP_DEFAULT_PRECIS, DEFAULT_QUALITY, DEFAULT_PITCH | FF_DONTCARE, "Arial");
    SelectObject(hdc, hFont);

    // Set the margins
    RECT rcMargin;
    rcMargin.left = leftMargin;
    rcMargin.top = topMargin;
    rcMargin.right = 0;
    rcMargin.bottom = 0;
    SetTextCharacterExtra(hdc, rcMargin.left);
    SetTextAlign(hdc, TA_LEFT | TA_TOP);

    // Draw the text
    TextOut(hdc, leftMargin, topMargin, "Hello, World!", lstrlen("Hello, World!"));

    // Cleanup
    DeleteObject(hFont);
    ReleaseDC(NULL, hdc);

    return 0;
}