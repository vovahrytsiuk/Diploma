#include <UI/BaseApplication.h>
#include <Parser/Parser.h>

BaseApplication::BaseApplication() : _hInstance{GetModuleHandle(NULL)}
{
    Parser parser;
    parser.parcing();
    auto param = parser.getResult();
    _mainWindow = Window(param.getName(), Size(param.getSizeVert(), param.getSizeGorz()), _hInstance);
    createMainWindowWidgets(param);
    _mainWindow.render();
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
    _mainWindow.addWidget<Button>(params.getName(), Size{params.getSizeVert(), params.getSizeGorz()}, Position{params.getPositionGorz(), params.getPositionVert()}, Text{params.text.getText()}, params.getClicable(), params.getDoubleClicable());
}

void BaseApplication::createLabelMock(const ParamsMock::Label &params)
{
    _mainWindow.addWidget<Label>(params._name, Size{params._height, params._width}, Position{params._x, params._y}, Text{params._text});
}

void BaseApplication::createLabel(const Params::Label &params)
{
    _mainWindow.addWidget<Label>(params.getName(), Size{50, 200}, Position{params.getPositionGorz(), params.getPositionVert()}, Text{params.text.getText()});
}

void BaseApplication::createFieldEditMock(const ParamsMock::FieldEdit &params)
{
    _mainWindow.addWidget<FieldEdit>(params._name, Size(params._height, params._width), Position(params._x, params._y), Text(""));
}

void BaseApplication::createFieldEdit(const Params::EditLine &params)
{
    _mainWindow.addWidget<FieldEdit>(params.getName(), Size(params.getSizeVert(), params.getSizeGorz()), Position(params.getPositionGorz(), params.getPositionVert()), Text(""));
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
    _mainWindow.addWidget<RadioButton>(params.getName(), Size{50, 100}, Position{params.getPositionGorz(), params.getPositionVert()}, Text{params.text.getText()}, true, true);
}

void BaseApplication::createCkeckBoxMock(const ParamsMock::CheckBox &params)
{
    _mainWindow.addWidget<CheckBox>(params._name, Size{params._height, params._width}, Position{params._x, params._y}, Text{params._text}, params._clickable);
}

void BaseApplication::createCkeckBox(const Params::CheckBox &params)
{
    _mainWindow.addWidget<CheckBox>(params.getName(), Size{50, 100}, Position{params.getPositionGorz(), params.getPositionVert()}, Text{params.text.getText()}, params.getClicable());
}
