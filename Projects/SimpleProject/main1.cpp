// #pragma once

#include <windows.h>

// Step 1: Declare the window procedure
LRESULT CALLBACK WindowProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam);

// Global variables for radio buttons in Group 1
HWND hGroup1RadioButton1, hGroup1RadioButton2;

// Global variables for radio buttons in Group 2
HWND hGroup2RadioButton1, hGroup2RadioButton2;

int WINAPI WinMain(HINSTANCE hInstance, [[maybe_unused]] HINSTANCE hPrevInstance, [[maybe_unused]] LPSTR lpCmdLine, int nCmdShow)
{
    // Step 2: Register the window class
    const wchar_t CLASS_NAME[] = "Multiple Radio Groups Window Class";

    WNDCLASS wc = {};
    wc.lpfnWndProc = WindowProc;
    wc.hInstance = hInstance;
    wc.lpszClassName = CLASS_NAME;

    RegisterClass(&wc);

    // Step 3: Create the window
    HWND hwnd = CreateWindowEx(
        0,                               // Optional window styles
        CLASS_NAME,                      // Window class name
        "Multiple Radio Groups Example", // Window title
        WS_OVERLAPPEDWINDOW,             // Window style

        // Size and position
        CW_USEDEFAULT, CW_USEDEFAULT, CW_USEDEFAULT, CW_USEDEFAULT,

        NULL,      // Parent window
        NULL,      // Menu
        hInstance, // Instance handle
        NULL       // Additional application data
    );

    if (hwnd == NULL)
    {
        return 0;
    }

    // Step 4: Create radio buttons for Group 1
    hGroup1RadioButton1 = CreateWindowEx(
        0,                                          // Optional window styles
        "BUTTON",                                   // Control class name
        "Option 1 (Group 1)",                       // Control text
        WS_CHILD | WS_VISIBLE | BS_AUTORADIOBUTTON, // Control styles

        // Size and position
        50, 50, 150, 25,

        hwnd,      // Parent window
        NULL,      // Control identifier
        hInstance, // Instance handle
        NULL       // Additional control data
    );

    hGroup1RadioButton2 = CreateWindowEx(
        0,                                          // Optional window styles
        "BUTTON",                                   // Control class name
        "Option 2 (Group 1)",                       // Control text
        WS_CHILD | WS_VISIBLE | BS_AUTORADIOBUTTON, // Control styles

        // Size and position
        50, 80, 150, 25,

        hwnd,      // Parent window
        NULL,      // Control identifier
        hInstance, // Instance handle
        NULL       // Additional control data
    );

    // Set the first radio button in Group 1 as the initially selected one
    SendMessage(hGroup1RadioButton1, BM_SETCHECK, BST_CHECKED, 0);

    // Step 5: Create radio buttons for Group 2
    hGroup2RadioButton1 = CreateWindowEx(
        0,                                          // Optional window styles
        "BUTTON",                                   // Control class name
        "Option 1 (Group 2)",                       // Control text
        WS_CHILD | WS_VISIBLE | BS_AUTORADIOBUTTON, // Control styles

        // Size and position
        250, 50, 150, 25,

        hwnd,      // Parent window
        NULL,      // Control identifier
        hInstance, // Instance handle
        NULL       // Additional control data
    );

    hGroup2RadioButton2 = CreateWindowEx(
        0,                                          // Optional window styles
        "BUTTON",                                   // Control class name
        "Option 2 (Group 2)",                       // Control text
        WS_CHILD | WS_VISIBLE | BS_AUTORADIOBUTTON, // Control styles

        // Size and position
        250, 80, 150, 25,

        hwnd,      // Parent window
        NULL,      // Control identifier
        hInstance, // Instance handle
        NULL       // Additional control data
    );

    // Set the first radio button in Group 2 as the initially selected one
    SendMessage(hGroup2RadioButton1, BM_SETCHECK, BST_CHECKED, 0);

    // Step 6: Show the window
    ShowWindow(hwnd, nCmdShow);

    // Step 7: Run the message loop
    MSG msg = {};
    while (GetMessage(&msg, NULL, 0, 0))
    {
        TranslateMessage(&msg);
        DispatchMessage(&msg);
    }

    return 0;
}

// Step 8: Implement the window procedure
LRESULT CALLBACK WindowProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam)
{
    switch (uMsg)
    {
    case WM_COMMAND:
    {
        // Handle radio button selection changes
        if (HIWORD(wParam) == BN_CLICKED)
        {
            // Check which radio button was clicked in Group 1
            if ((HWND)lParam == hGroup1RadioButton1)
            {
                MessageBox(hwnd, "Option 1 (Group 1) selected", "Radio Groups", MB_OK);
            }
            else if ((HWND)lParam == hGroup1RadioButton2)
            {
                MessageBox(hwnd, "Option 2 (Group 1) selected", "Radio Groups", MB_OK);
            }
            // Check which radio button was clicked in Group 2
            else if ((HWND)lParam == hGroup2RadioButton1)
            {
                MessageBox(hwnd, "Option 1 (Group 2) selected", "Radio Groups", MB_OK);
            }
            else if ((HWND)lParam == hGroup2RadioButton2)
            {
                MessageBox(hwnd, "Option 2 (Group 2) selected", "Radio Groups", MB_OK);
            }
        }
        break;
    }

    case WM_DESTROY:
        PostQuitMessage(0);
        return 0;

    default:
        return DefWindowProc(hwnd, uMsg, wParam, lParam);
    }
    return DefWindowProc(hwnd, uMsg, wParam, lParam);
}
