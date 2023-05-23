#include <UI/BaseApplication.h>

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

int main()
{
    BaseApplication app;

    if (auto *button = app.GetMainWindow().findWidgetById<Button>(1); button)
    {
        button->_click.connect(buttonClicked);
    }

    if (auto *button = app.GetMainWindow().findWidgetById<Button>(2); button)
    {
        button->_doubleClick.connect(buttonDoubleClicked);
    }

    app.runMessageLoop();
    return 0;
}
