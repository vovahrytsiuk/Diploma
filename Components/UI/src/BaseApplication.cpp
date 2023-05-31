#include <UI/BaseApplication.h>

void BaseApplication::createMainWindowWidgets(const WindowParams &params)
{
    createWidgets(params._buttons, &BaseApplication::createButton);
    createWidgets(params._checkBoxes, &BaseApplication::createCkeckBox);
    createWidgets(params._labels, &BaseApplication::createLabel);
    createWidgets(params._spinBoxes, &BaseApplication::createSpinBox);
    createWidgets(params._lineEdits, &BaseApplication::createFieldEdit);
}

void BaseApplication::createButton(const ButtonParams &params)
{
    _mainWindow.addWidget<Button>(params._name, Size{params._height, params._width}, Position{params._x, params._y}, Text{params._text});
}

void BaseApplication::createLabel(const LabelParams &params)
{
    _mainWindow.addWidget<Label>(params._name, Size{params._height, params._width}, Position{params._x, params._y}, Text{params._text});
}

void BaseApplication::createFieldEdit(const FieldEditParams &params)
{
    _mainWindow.addWidget<FieldEdit>(params._name, Size(params._height, params._width), Position(params._x, params._y), Text(""));
}

void BaseApplication::createSpinBox(const SpinBoxParams &params)
{
    auto id = _mainWindow.addWidget<Edit>(params._name + "DefaultSystemEdit", Size(params._height, params._width), Position(params._x, params._y));
    _mainWindow.addWidget<SpinBox>(params._name, params._upper, params._lower, params._default, id);
}

void BaseApplication::createRadioButton(const RadioButtonParams &)
{
    // TODO
}

void BaseApplication::createImageField(const ImageFieldParams &)
{
    // TODO
}

void BaseApplication::createCkeckBox(const CheckBoxParams &params)
{
    _mainWindow.addWidget<CheckBox>(params._name, Size{params._height, params._width}, Position{params._x, params._y}, Text{params._text});
}
