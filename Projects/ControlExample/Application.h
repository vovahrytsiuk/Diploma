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
            auto *labelA = _mainWindow.findWidgetByName<FieldEdit>("Coefficient_X_Squared");
            auto *labelB = _mainWindow.findWidgetByName<FieldEdit>("Coefficient_X");
            auto *labelC = _mainWindow.findWidgetByName<FieldEdit>("Coefficient_Free_Member");
            QuadraticEquation eq(
                std::stod(labelA->getText().c_str()),
                std::stod(labelB->getText().c_str()),
                std::stod(labelC->getText().c_str()));
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