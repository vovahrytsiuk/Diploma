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
    std::unordered_map<int, int> _clickCounters;

    if (auto *button = app.GetMainWindow().findWidgetById<Button>(1); button)
    {
        button->_click.connect(buttonClicked);
        auto *label = app.GetMainWindow().findWidgetById<Label>(5);
        button->_click.connect([label, &_clickCounters, button]()
                               { updateCounterAndLabelText(button->getId(), label, _clickCounters); });
    }

    if (auto *button = app.GetMainWindow().findWidgetById<Button>(2); button)
    {
        button->_doubleClick.connect(buttonDoubleClicked);
        auto *label = app.GetMainWindow().findWidgetById<Label>(6);
        button->_doubleClick.connect([label, &_clickCounters, button]()
                                     { updateCounterAndLabelText(button->getId(), label, _clickCounters); });
    }

    if (auto *button = app.GetMainWindow().findWidgetById<Button>(3); button)
    {
        auto *label = app.GetMainWindow().findWidgetById<Label>(7);
        auto *lineEdit = app.GetMainWindow().findWidgetById<LineEdit>(10);
        button->_click.connect([lineEdit, label, &_clickCounters, button]()
                               { updateLableWithCounter(button->getId(), lineEdit, label, _clickCounters); });
    }

    if (auto *lineEdit = app.GetMainWindow().findWidgetById<LineEdit>(10); lineEdit)
    {
        auto *label = app.GetMainWindow().findWidgetById<Label>(11);
        lineEdit->_textChanged.connect([lineEdit, label]()
                                       { label->setText(lineEdit->getText()); });
    }

    app.runMessageLoop();
    return 0;
}
