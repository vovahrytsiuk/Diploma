#pragma once
#include <iostream>
#include <vector>

#include "Button.h"
#include "Label.h"
#include "NumberBox.h"
#include "CheckBox.h"
#include "RadioButton.h"
#include "EditLine.h"

namespace Params
{
    class Form
    {
    public:
        Form() = default;
        ~Form() = default;

        void setSizeVert(int info);
        int getSizeVert() const;
        void setSizeGorz(int info);
        int getSizeGorz() const;
        void setName(std::string info);
        std::string getName() const;

        void createButton();
        void createLabel();
        void createNumberBox();
        void createCheckBox();
        void createRadioButton();
        void createEditLine();

        std::vector<Button> buttons;
        std::vector<Label> labels;
        std::vector<NumberBox> numberBoxes;
        std::vector<CheckBox> checkBoxes;
        std::vector<RadioButton> radioButtones;
        std::vector<EditLine> editLines;

    private:
        int sizeVert = 720;
        int sizeGorz = 1200;
        std::string name = "Form";
    };
}