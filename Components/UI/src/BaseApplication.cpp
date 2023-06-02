#include <UI/BaseApplication.h>

void BaseApplication::createMainWindowWidgets(const Params::Window &params)
{
    createWidgets(params._buttons, &BaseApplication::createButton);
    createWidgets(params._checkBoxes, &BaseApplication::createCkeckBox);
    createWidgets(params._labels, &BaseApplication::createLabel);
    createWidgets(params._spinBoxes, &BaseApplication::createSpinBox);
    createWidgets(params._lineEdits, &BaseApplication::createFieldEdit);
    createWidgets(params._radioButtons, &BaseApplication::createRadioButton);
}

void BaseApplication::createButton(const Params::Button &params)
{
    _mainWindow.addWidget<Button>(params._name, Size{params._height, params._width}, Position{params._x, params._y}, Text{params._text}, params._clickable, params._doubleClickable);
}

void BaseApplication::createLabel(const Params::Label &params)
{
    _mainWindow.addWidget<Label>(params._name, Size{params._height, params._width}, Position{params._x, params._y}, Text{params._text});
}

void BaseApplication::createFieldEdit(const Params::FieldEdit &params)
{
    _mainWindow.addWidget<FieldEdit>(params._name, Size(params._height, params._width), Position(params._x, params._y), Text(""));
}

void BaseApplication::createSpinBox(const Params::SpinBox &params)
{
    auto id = _mainWindow.addWidget<Edit>(params._name + "DefaultSystemEdit", Size(params._height, params._width), Position(params._x, params._y));
    _mainWindow.addWidget<SpinBox>(params._name, params._upper, params._lower, params._default, id);
}

void BaseApplication::createRadioButton(const Params::RadioButton &params)
{
    _mainWindow.addWidget<RadioButton>(params._name, Size{params._height, params._width}, Position{params._x, params._y}, Text{params._text}, params._clickable, params._newGroup);
}

void BaseApplication::createCkeckBox(const Params::CheckBox &params)
{
    _mainWindow.addWidget<CheckBox>(params._name, Size{params._height, params._width}, Position{params._x, params._y}, Text{params._text}, params._clickable);
}
