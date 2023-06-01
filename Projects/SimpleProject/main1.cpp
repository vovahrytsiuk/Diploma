
#pragma warning(disable : 4458)
#include <Windows.h>
#include <gdiplus.h>
using namespace Gdiplus;

LRESULT CALLBACK WndProc(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam);

int WINAPI WinMain(HINSTANCE hInstance, [[maybe_unused]] HINSTANCE hPrevInstance, [[maybe_unused]] LPSTR lpCmdLine, int nCmdShow)
{
    // Initialize GDI+
    GdiplusStartupInput gdiplusStartupInput;
    ULONG_PTR gdiplusToken;
    GdiplusStartup(&gdiplusToken, &gdiplusStartupInput, NULL);

    // Create the window
    const char CLASS_NAME[] = "MyWindowClass";
    WNDCLASS wc = {0};
    wc.lpfnWndProc = WndProc;
    wc.hInstance = hInstance;
    wc.lpszClassName = CLASS_NAME;
    RegisterClass(&wc);

    HWND hWnd = CreateWindowEx(
        0, CLASS_NAME, "Image Window",
        WS_OVERLAPPEDWINDOW, CW_USEDEFAULT, CW_USEDEFAULT,
        500, 500, NULL, NULL, hInstance, NULL);

    if (hWnd == NULL)
        return 0;

    // Load and display the image
    HDC hdc = GetDC(hWnd);
    Graphics graphics(hdc);
    Image image(L"R.png");
    graphics.DrawImage(&image, 10, 10);

    // Clean up GDI+
    ReleaseDC(hWnd, hdc);
    GdiplusShutdown(gdiplusToken);

    // Display the window
    ShowWindow(hWnd, nCmdShow);

    // Run the message loop
    MSG msg = {0};
    while (GetMessage(&msg, NULL, 0, 0))
    {
        TranslateMessage(&msg);
        DispatchMessage(&msg);
    }

    return static_cast<WORD>(msg.wParam);
}

LRESULT CALLBACK WndProc(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam)
{
    switch (msg)
    {
    case WM_DESTROY:
        PostQuitMessage(0);
        return 0;
    }

    return DefWindowProc(hWnd, msg, wParam, lParam);
}
