#include <UI/BaseApplication.h>

#include <string>

void buttonClicked()
{
    std::wstring message = L"Button clicked";
    int msgboxID = MessageBox(
        NULL,
        message.data(),
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

void buttonDoubleClicked()
{
    std::wstring message = L"Button double clicked";
    int msgboxID = MessageBox(
        NULL,
        message.data(),
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

void updateCounterAndLabelText(int buttonId, Label *label, std::unordered_map<int, int> &counters)
{
    ++counters[buttonId];
    label->setText(L"Button " + std::to_wstring(buttonId) + L" clicked " + std::to_wstring(counters[buttonId]) + L" times");
}

void updateLableWithCounter(int buttonId, LineEdit *lineEdit, Label *label, std::unordered_map<int, int> &counters)
{
    ++counters[buttonId];
    label->setText(L"Button " + std::to_wstring(buttonId) + L" clicked " + std::to_wstring(counters[buttonId] * stoi(lineEdit->getText())) + L" times");
}

int main()
{
    BaseApplication app;

    // For demo logic
    // std::unordered_map<int, int> _clickCounters;

    // if (auto *button = app.GetMainWindow().findWidgetById<Button>(1); button)
    // {
    //     button->_click.connect(buttonClicked);
    //     auto *label = app.GetMainWindow().findWidgetById<Label>(5);
    //     button->_click.connect([label, &_clickCounters, button]()
    //                            { updateCounterAndLabelText(button->getId(), label, _clickCounters); });
    // }

    // if (auto *button = app.GetMainWindow().findWidgetById<Button>(2); button)
    // {
    //     button->_doubleClick.connect(buttonDoubleClicked);
    //     auto *label = app.GetMainWindow().findWidgetById<Label>(6);
    //     button->_doubleClick.connect([label, &_clickCounters, button]()
    //                                  { updateCounterAndLabelText(button->getId(), label, _clickCounters); });
    // }

    // if (auto *button = app.GetMainWindow().findWidgetById<Button>(3); button)
    // {
    //     auto *label = app.GetMainWindow().findWidgetById<Label>(7);
    //     auto *lineEdit = app.GetMainWindow().findWidgetById<LineEdit>(10);
    //     button->_click.connect([lineEdit, label, &_clickCounters, button]()
    //                            { updateLableWithCounter(button->getId(), lineEdit, label, _clickCounters); });
    // }

    // if (auto *lineEdit = app.GetMainWindow().findWidgetById<LineEdit>(10); lineEdit)
    // {
    //     auto *label = app.GetMainWindow().findWidgetById<Label>(11);
    //     lineEdit->_textChanged.connect([lineEdit, label]()
    //                                    { label->setText(lineEdit->getText()); });
    // }

    app.runMessageLoop();
    return 0;
}

// #pragma once
// #ifndef UNICODE
// #define UNICODE
// #endif

// #include <windows.h>
// #include <commctrl.h>
// #include <strsafe.h>

// #define ID_UPDOWN 1
// #define ID_EDIT 2
// #define ID_STATIC 3
// #define UD_MAX_POS 30
// #define UD_MIN_POS 0

// LRESULT CALLBACK WndProc(HWND, UINT, WPARAM, LPARAM);
// void CreateControls(HWND);

// HWND hUpDown, hEdit, hStatic;

// int WINAPI wWinMain(HINSTANCE hInstance, [[maybe_unused]] HINSTANCE hPrevInstance,
//                     [[maybe_unused]] PWSTR lpCmdLine, [[maybe_unused]] int nCmdShow)
// {

//     MSG msg;
//     WNDCLASSW wc = {0};

//     wc.style = CS_HREDRAW | CS_VREDRAW;
//     wc.lpszClassName = L"Updown control";
//     wc.hInstance = hInstance;
//     wc.hbrBackground = GetSysColorBrush(COLOR_3DFACE);
//     wc.lpfnWndProc = WndProc;
//     wc.hCursor = LoadCursor(0, IDC_ARROW);

//     RegisterClassW(&wc);
//     CreateWindowW(wc.lpszClassName, L"Updown control",
//                   WS_OVERLAPPEDWINDOW | WS_VISIBLE,
//                   100, 100, 280, 200, NULL, NULL, hInstance, NULL);

//     while (GetMessage(&msg, NULL, 0, 0))
//     {

//         DispatchMessage(&msg);
//     }

//     return (int)msg.wParam;
// }

// LRESULT CALLBACK WndProc(HWND hwnd, UINT msg,
//                          WPARAM wParam, LPARAM lParam)
// {

//     LPNMUPDOWN lpnmud;
//     UINT code;

//     switch (msg)
//     {

//     case WM_CREATE:

//         CreateControls(hwnd);

//         break;

//     case WM_NOTIFY:

//         code = ((LPNMHDR)lParam)->code;

//         if (code == UDN_DELTAPOS)
//         {

//             lpnmud = (NMUPDOWN *)lParam;

//             int value = lpnmud->iPos + lpnmud->iDelta;

//             if (value < UD_MIN_POS)
//             {
//                 value = UD_MIN_POS;
//             }

//             if (value > UD_MAX_POS)
//             {
//                 value = UD_MAX_POS;
//             }

//             const int asize = 4;
//             wchar_t buf[asize];
//             size_t cbDest = asize * sizeof(wchar_t);
//             StringCbPrintfW(buf, cbDest, L"%d", value);

//             SetWindowTextW(hStatic, buf);
//         }

//         break;

//     case WM_DESTROY:
//         PostQuitMessage(0);
//         break;
//     }

//     return DefWindowProcW(hwnd, msg, wParam, lParam);
// }

// void CreateControls(HWND hwnd)
// {

//     INITCOMMONCONTROLSEX icex;

//     icex.dwSize = sizeof(INITCOMMONCONTROLSEX);
//     icex.dwICC = ICC_UPDOWN_CLASS;
//     InitCommonControlsEx(&icex);

//     hUpDown = CreateWindowW(UPDOWN_CLASSW, NULL, WS_CHILD | WS_VISIBLE | UDS_SETBUDDYINT | UDS_ALIGNRIGHT,
//                             0, 0, 0, 0, hwnd, (HMENU)ID_UPDOWN, NULL, NULL);

//     hEdit = CreateWindowExW(WS_EX_CLIENTEDGE, WC_EDITW, NULL, WS_CHILD | WS_VISIBLE | ES_RIGHT, 15, 15, 70, 25, hwnd,
//                             (HMENU)ID_EDIT, NULL, NULL);

//     hStatic = CreateWindowW(WC_STATICW, L"0", WS_CHILD | WS_VISIBLE | SS_LEFT, 15, 60, 300, 230, hwnd, (HMENU)ID_STATIC, NULL, NULL);

//     SendMessageW(hUpDown, UDM_SETBUDDY, (WPARAM)hEdit, 0);
//     SendMessageW(hUpDown, UDM_SETRANGE, 0, MAKELPARAM(UD_MAX_POS, UD_MIN_POS));
//     SendMessageW(hUpDown, UDM_SETPOS32, 0, 0);
// }