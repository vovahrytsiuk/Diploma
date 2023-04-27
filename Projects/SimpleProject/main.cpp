#ifndef UNICODE
#define UNICODE
#endif

#include <UI/Window.h>
#include <UI/Widgets/Button.h>


int WINAPI wWinMain(HINSTANCE hInstance, [[maybe_unused]] HINSTANCE hPrevInstance, [[maybe_unused]] PWSTR pCmdLine, int nCmdShow)
{
    
    Window window(hInstance, hPrevInstance, pCmdLine, nCmdShow);
    return 0;
}