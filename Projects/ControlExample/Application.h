#pragma once
#include <UI/BaseApplication.h>
#include <string>

/**
 * @brief _ax^2 + _bx + _c = 0
 */
class QuadraticEquation
{
public:
    QuadraticEquation(double a, double b, double c) : _a{a}, _b{b}, _c{c} {}
    std::string getRootsString(bool printDiscriminant) const
    {
        std::string answer = "";
        double d = _b * _b - 4 * _a * _c;
        if (printDiscriminant)
        {
            answer.append("Discriminant = " + std::to_string(d) + "\n");
        }
        if (d < 0)
        {
            answer.append("Quadratic equation has no roots\n");
        }
        else if (d == 0)
        {
            answer.append("Quadratic equation has one root\n");
            answer.append("x = " + std::to_string(-1 * _b / 2 / _a));
        }
        else
        {
            answer.append("Quadratic equation has two roots\n");
            answer.append("x1 = " + std::to_string((-1 * _b + sqrt(d)) / 2 / _a));
            answer.append("\nx2 = " + std::to_string((-1 * _b - sqrt(d)) / 2 / _a));
        }
        return answer;
    }

private:
    double _a;
    double _b;
    double _c;
};

class Application : public BaseApplication
{
public:
    Application();

    void calculate()
    {
        try
        {
            auto *fieldA = _mainWindow.findWidgetByName<FieldEdit>("Coefficient_X_Squared");
            auto *fieldB = _mainWindow.findWidgetByName<FieldEdit>("Coefficient_X");
            auto *fieldC = _mainWindow.findWidgetByName<FieldEdit>("Coefficient_Free_Member");
            auto aString = fieldA->getText();
            auto bString = fieldB->getText();
            auto cString = fieldC->getText();
            auto a = std::stod(aString.c_str());
            auto b = std::stod(bString.c_str());
            auto c = std::stod(cString.c_str());
            QuadraticEquation eq(a, b, c);

            auto *checkBoxShowDisc = _mainWindow.findWidgetByName<CheckBox>("CheckBox_Show_Discriminant");
            auto *label = _mainWindow.findWidgetByName<Label>("Label_Answer");
            label->setText(eq.getRootsString(checkBoxShowDisc->isChecked()));
        }
        catch (...)
        {
            auto *label = _mainWindow.findWidgetByName<Label>("Label_Answer");
            label->setText("Invalid arguments");
        }
    }

private:
};