#include <Params/Form.h>

using namespace Params;

void Form::setSizeVert(int info)
{
    sizeVert = info;
    std::cout << "Set sizeVert: " << info << " for " << name << '\n';
}

int Form::getSizeVert() const
{
    return sizeVert;
}

void Form::setSizeGorz(int info)
{
    sizeGorz = info;
    std::cout << "Set sizeGorz: " << info << " for " << name << '\n';
}

int Form::getSizeGorz() const
{
    return sizeGorz;
}

void Form::createButton()
{
    Button button;
    buttons.push_back(button);
    std::cout << "Create button in " << name << '\n';
}

void Form::createLabel()
{
    Label label;
    labels.push_back(label);
    std::cout << "Create label in " << name << '\n';
}

void Form::createNumberBox()
{
    NumberBox numberBox;
    numberBoxes.push_back(numberBox);
    std::cout << "Create numberBox in " << name << '\n';
}

void Form::createCheckBox()
{
    CheckBox checkBox;
    checkBoxes.push_back(checkBox);
    std::cout << "Create checkBox in " << name << '\n';
}

void Form::createRadioButton()
{
    RadioButton radioButton;
    radioButtones.push_back(radioButton);
    std::cout << "Create rdioButton in " << name << '\n';
}

void Form::createEditLine()
{
    EditLine editLine;
    editLines.push_back(editLine);
    std::cout << "Create editLine in " << name << '\n';
}

void Form::setName(std::string info)
{
    name = info;
    std::cout << "Set name: " << info << " for " << name << '\n';
}

std::string Form::getName() const
{
    return name;
}