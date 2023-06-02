#pragma once
#include <iostream>
#include <vector>

#include "Button.h"
#include "Label.h"
#include "NumberBox.h"
#include "CheckBox.h"
#include "RadioButton.h"
#include "EditLine.h"
#include "Image.h"
class Form
{
public:
	Form() = default;
	~Form() = default;


	void setSizeVert(int info);
	int  getSizeVert();
	void setSizeGorz(int info);
	int  getSizeGorz();
	void setName(std::string info);
	std::string getName();


	void createButton();
	void createLabel();
	void createNumberBox();
	void createCheckBox();
	void createRadioButton();
	void createEditLine();
	void createImage();


	std::vector<Button> buttons;
	std::vector<Label>  labels;
	std::vector<NumberBox> numberBoxes;
	std::vector<CheckBox> checkBoxes;
	std::vector<RadioButton> radioButtones;
	std::vector<EditLine> editLines;
	std::vector<Image> images;
private:
	int sizeVert = 720;
	int sizeGorz = 1200;
	std::string name = "Form";



};

