#include <UI/BaseApplication.h>
#include <Parser/Parser.h>
#include <algorithm>
#include <unordered_set>

BaseApplication::BaseApplication() : _hInstance{GetModuleHandle(NULL)}
{
    Parser parser;
    parser.parcing();
    auto param = parser.getResult();
    if (parser.getError().empty())
    {
        // sort radioButtons
        // radioButtons from different groups should be created without shufling
        sortRadioButtonsByGroupNames(param);
        _mainWindow = Window(param.getName(), Size(param.getSizeVert(), param.getSizeGorz()), _hInstance);
        createMainWindowWidgets(param);
    }
    else
    {
        // Error window
        _mainWindow = Window("Error Information", Size(300, 400), _hInstance);
        _mainWindow.addWidget<Label>("Error", Size{250, 350}, Position{15, 15}, Text{parser.getError()});
    }

    _mainWindow.render();
}

void BaseApplication::sortRadioButtonsByGroupNames(Params::Form &params)
{
    std::sort(params.radioButtones.begin(), params.radioButtones.end(), [](const Params::RadioButton &rb1, const Params::RadioButton &rb2)
              { return rb1.getGroupName() < rb2.getGroupName(); });
}

void BaseApplication::createMainWindowWidgets(const ParamsMock::Window &params)
{
    createWidgets(params._buttons, &BaseApplication::createButtonMock);
    createWidgets(params._checkBoxes, &BaseApplication::createCkeckBoxMock);
    createWidgets(params._labels, &BaseApplication::createLabelMock);
    createWidgets(params._spinBoxes, &BaseApplication::createSpinBoxMock);
    createWidgets(params._lineEdits, &BaseApplication::createFieldEditMock);
    createWidgets(params._radioButtons, &BaseApplication::createRadioButtonMock);
}

void BaseApplication::createMainWindowWidgets(const Params::Form &params)
{
    createWidgets(params.buttons, &BaseApplication::createButton);
    createWidgets(params.checkBoxes, &BaseApplication::createCkeckBox);
    createWidgets(params.labels, &BaseApplication::createLabel);
    createWidgets(params.numberBoxes, &BaseApplication::createSpinBox);
    createWidgets(params.editLines, &BaseApplication::createFieldEdit);
    createWidgets(params.radioButtones, &BaseApplication::createRadioButton);
}

void BaseApplication::createButtonMock(const ParamsMock::Button &params)
{
    _mainWindow.addWidget<Button>(params._name, Size{params._height, params._width}, Position{params._x, params._y}, Text{params._text}, params._clickable, params._doubleClickable);
}

void BaseApplication::createButton(const Params::Button &params)
{
    _mainWindow.addWidget<Button>(params.getName(), Size{params.getSizeVert(), params.getSizeGorz()}, Position{params.getPositionGorz(), params.getPositionVert()}, Text{params.text.getText(), Font(params.text.getHeight(), params.text.getBold(), params.text.getItalic(), params.text.getUnderline(), false, params.text.getTitle())}, params.getClicable(), params.getDoubleClicable());
}

void BaseApplication::createLabelMock(const ParamsMock::Label &params)
{
    _mainWindow.addWidget<Label>(params._name, Size{params._height, params._width}, Position{params._x, params._y}, Text{params._text});
}

void BaseApplication::createLabel(const Params::Label &params)
{
    _mainWindow.addWidget<Label>(params.getName(), Size{params.getSizeVert(), params.getSizeGorz()}, Position{params.getPositionGorz(), params.getPositionVert()}, Text{params.text.getText(), Font(params.text.getHeight(), params.text.getBold(), params.text.getItalic(), params.text.getUnderline(), false, params.text.getTitle())});
}

void BaseApplication::createFieldEditMock(const ParamsMock::FieldEdit &params)
{
    _mainWindow.addWidget<FieldEdit>(params._name, Size(params._height, params._width), Position(params._x, params._y), Text(""));
}

void BaseApplication::createFieldEdit(const Params::EditLine &params)
{
    _mainWindow.addWidget<FieldEdit>(params.getName(), Size(params.getSizeVert(), params.getSizeGorz()), Position(params.getPositionGorz(), params.getPositionVert()), Text("", Font(params.text.getHeight(), params.text.getBold(), params.text.getItalic(), params.text.getUnderline(), false, params.text.getTitle())));
}

void BaseApplication::createSpinBoxMock(const ParamsMock::SpinBox &params)
{
    auto id = _mainWindow.addWidget<Edit>(params._name + "DefaultSystemEdit", Size(params._height, params._width), Position(params._x, params._y));
    _mainWindow.addWidget<SpinBox>(params._name, params._upper, params._lower, params._default, id);
}

void BaseApplication::createSpinBox(const Params::NumberBox &params)
{
    auto id = _mainWindow.addWidget<Edit>(params.getName() + "DefaultSystemEdit", Size(50, 100), Position(params.getPositionGorz(), params.getPositionVert()));
    _mainWindow.addWidget<SpinBox>(params.getName(), params.getMaxValue(), params.getMinValue(), params.getDefaultValue(), id);
}

void BaseApplication::createRadioButtonMock(const ParamsMock::RadioButton &params)
{
    _mainWindow.addWidget<RadioButton>(params._name, Size{params._height, params._width}, Position{params._x, params._y}, Text{params._text}, params._clickable, params._newGroup);
}

void BaseApplication::createRadioButton(const Params::RadioButton &params)
{
    static std::unordered_set<std::string> processedGroupNames;
    auto result = processedGroupNames.insert(params.getGroupName());
    _mainWindow.addWidget<RadioButton>(params.getName(), Size{params.getSizeVert(), params.getSizeGorz()}, Position{params.getPositionGorz(), params.getPositionVert()}, Text{params.text.getText(), Font(params.text.getHeight(), params.text.getBold(), params.text.getItalic(), params.text.getUnderline(), false, params.text.getTitle())}, true, result.second);
}

void BaseApplication::createCkeckBoxMock(const ParamsMock::CheckBox &params)
{
    _mainWindow.addWidget<CheckBox>(params._name, Size{params._height, params._width}, Position{params._x, params._y}, Text{params._text}, params._clickable);
}

void BaseApplication::createCkeckBox(const Params::CheckBox &params)
{
    _mainWindow.addWidget<CheckBox>(params.getName(), Size{params.getSizeVert(), params.getSizeGorz()}, Position{params.getPositionGorz(), params.getPositionVert()}, Text{params.text.getText(), Font(params.text.getHeight(), params.text.getBold(), params.text.getItalic(), params.text.getUnderline(), false, params.text.getTitle())}, params.getClicable());
}
