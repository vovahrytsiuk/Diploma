#include "Parcer.h"

#include <iostream>
#include <string>

namespace NMMessages
{
	const std::string notOpenFile = "can not open file: ";
	const std::string unknCommand = "Unknown command";
	const std::string unknWidget = "Unknown widget or not in scope";
	const std::string createWidgetError = "This widget can't creating in this scope";
	const std::string outOfScope = "Out of any scopes";
	const std::string noParam = "Must be ':' in this line";
	const std::string noValue = "Must be value in this line";
	const std::string badParam = "This widget havent this param";
	const std::string badValue = "This line has invalid value or symbol after scope sign";
}

namespace NMCaommands
{
	const char create  = '|';
	const char param   = '/';
	const char comment = '#';
}

namespace NMWidgets
{
	const std::string form   = "Form";
	const std::string button = "Button";
	const std::string label  = "Label";
	const std::string text   = "Text";
	const std::string numberBox = "NumberBox";
	const std::string checkBox = "CheckBox";
	const std::string radioButton = "RadioButton";
	const std::string editLine = "EditLine";
}

bool checkInt(std::string info)
{
	for (size_t i = 0; i < info.size(); ++i)
	{
		if (info[i] != '0' &&
			info[i] != '1' &&
			info[i] != '2' &&
			info[i] != '3' &&
			info[i] != '4' &&
			info[i] != '5' &&
			info[i] != '6' &&
			info[i] != '7' &&
			info[i] != '8' &&
			info[i] != '9' &&
			info[i] != ' ')
		{
			return false;
		}
	}
	return true;
}

bool checkBool(std::string info)
{
	std::string temp;
	for (size_t i = 0; i < info.size(); ++i)
	{
		if (info[i] != ' ')
		{
			temp += info[i];
		}
	}
	if (temp != "true" && temp != "false")
	{
		return false;
	}
	return true;
}

bool getBool(std::string info)
{
	std::string temp;
	for (size_t i = 0; i < info.size(); ++i)
	{
		if (info[i] != ' ')
		{
			temp += info[i];
		}
	}
	if (temp == "true")
	{
		return true;
	}
	if (temp == "false")
	{
		return false;
	}
}

bool checkTitle(std::string info)
{
	if (info != "Calibri" && info != "Arial"
		&& info != "Times New Roman" && info != "Impact"
		&& info != "Corbel")
	{
		return false;
	}
	return true;
}

Parcer::Parcer()
{
	fin.open(pathFile);
}

Parcer::~Parcer()
{
	fin.close();
}

bool Parcer::checkFile()
{
	if (fin.is_open())
	{
		return true;
	}
	else
	{
		error.setError(NMMessages::notOpenFile + pathFile, line);
		return false;
	}
}

bool Parcer::parcing()
{
	scope.push(NMWidgets::form);

	while (!fin.eof())
	{
		if (scope.size() == 0)
		{
			error.setError(NMMessages::outOfScope, line);
			return false;
		}
		++line;
		std::getline(fin, parcingString);

		if (parcingString.size() > 0)
		{//////////////////////////////////////////////
			if (parcingString[0] == NMCaommands::create)
			{
				if (getWidget())
				{
					if (!createWidget())
					{
						error.setError(NMMessages::createWidgetError, line);
						return false;
					}
				}
				else
				{
					error.setError(NMMessages::unknWidget, line);
					return false;
				}
			}//////////////////////////////////////////////
			else if (parcingString[0] == NMCaommands::param)
			{
				if (getParam())
				{
					if (getValue())
					{
						if (checkParam())
						{
							if (!paramWidget())
							{
								error.setError(NMMessages::badValue, line);
								return false;
							}
						}
						else
						{
							error.setError(NMMessages::badParam, line);
							return false;
						}
					}
					else
					{
						error.setError(NMMessages::noValue, line);
						return false;
					}
				}
				else
				{
					error.setError(NMMessages::noParam, line);
					return false;
				}
			}/////////////////////////////////////////////////
			else if (parcingString[0] == NMCaommands::comment)
			{

			}
			else
			{////////////////////////////////////////////////
				error.setError(NMMessages::unknCommand, line);
				return false;
			}
		}
	}
	std::cout << '\n' << "Parcing done!" << '\n';
	return true;
}

bool Parcer::createWidget()
{
	if (scope.top() == NMWidgets::form)
	{
		if(activeString == NMWidgets::text)
		{
			return false;
		}
		if (activeString == NMWidgets::button)
		{
			scope.push(NMWidgets::button);
			form.createButton();
			//std::cout << '\n' << "Create button" << '\n';
		}
		if (activeString == NMWidgets::label)
		{
			scope.push(NMWidgets::label);
			form.createLabel();
			//std::cout << '\n' << "Create label" << '\n';
		}
		if (activeString == NMWidgets::numberBox)
		{
			scope.push(NMWidgets::numberBox);
			form.createNumberBox();
			//std::cout << '\n' << "Create numberBox" << '\n';
		}
		if (activeString == NMWidgets::checkBox)
		{
			scope.push(NMWidgets::checkBox);
			form.createCheckBox();
			//std::cout << '\n' << "Create checkBox" << '\n';
		}
		if (activeString == NMWidgets::radioButton)
		{
			scope.push(NMWidgets::radioButton);
			form.createRadioButton();
			//std::cout << '\n' << "Create radioButton" << '\n';
		}
		if (activeString == NMWidgets::editLine)
		{
			scope.push(NMWidgets::editLine);
			form.createEditLine();
			//std::cout << '\n' << "Create editLine" << '\n';
		}
	}
	else
	{
		if (activeString != NMWidgets::text)
		{
			return false;
		}
		scope.push(NMWidgets::text);
		std::cout << '\n' << "Create Text" << '\n';
	}

	return true;
}



bool Parcer::paramWidget()
{
	//valueString
	//parcingString
	//activeString
	if (scope.top() == NMWidgets::text)
	{
		scope.pop();

		if (scope.top() == NMWidgets::button)
		{
			if (activeString == "text")
			{
				form.buttons[form.buttons.size() - 1].text.setText(valueString);
			}
			if (activeString == "positionVert")
			{
				if (!checkInt(valueString))
				{
					return false;
				}
				else
				{
					form.buttons[form.buttons.size() - 1].text.setPositionVert(std::stoi(valueString));
				}
			}
			if (activeString == "positionGorz")
			{
				if (!checkInt(valueString))
				{
					return false;
				}
				else
				{
					form.buttons[form.buttons.size() - 1].text.setPositionGorz(std::stoi(valueString));
				}
			}
			if (activeString == "height")
			{
				if (!checkInt(valueString))
				{
					return false;
				}
				else
				{
					form.buttons[form.buttons.size() - 1].text.setHeight(std::stoi(valueString));
				}
			}
			if (activeString == "italic")
			{
				if (checkBool(valueString))
				{
					if (getBool(valueString))
					{
						form.buttons[form.buttons.size() - 1].text.setItalic(true);
					}
					else
					{
						form.buttons[form.buttons.size() - 1].text.setItalic(false);
					}
				}
				else
				{
					return false;
				}
			}
			if (activeString == "underline")
			{
				if (checkBool(valueString))
				{
					if (getBool(valueString))
					{
						form.buttons[form.buttons.size() - 1].text.setUnderline(true);
					}
					else
					{
						form.buttons[form.buttons.size() - 1].text.setUnderline(false);
					}
				}
				else
				{
					return false;
				}
			}
			if (activeString == "bold")
			{
				if (checkBool(valueString))
				{
					if (getBool(valueString))
					{
						form.buttons[form.buttons.size() - 1].text.setBold(true);
					}
					else
					{
						form.buttons[form.buttons.size() - 1].text.setBold(false);
					}
				}
				else
				{
					return false;
				}	
			}
			if (activeString == "title")
			{
				if(checkTitle(valueString))
				{
					form.buttons[form.buttons.size() - 1].text.setTitle(valueString);
				}
				else
				{
					return false;
				}
			}
			
		}

		if (scope.top() == NMWidgets::label)
		{
			if (activeString == "text")
			{
				form.labels[form.labels.size() - 1].text.setText(valueString);
			}
			if (activeString == "positionVert")
			{
				if (!checkInt(valueString))
				{
					return false;
				}
				else
				{
					form.labels[form.labels.size() - 1].text.setPositionVert(std::stoi(valueString));
				}
			}
			if (activeString == "positionGorz")
			{
				if (!checkInt(valueString))
				{
					return false;
				}
				else
				{
					form.labels[form.labels.size() - 1].text.setPositionGorz(std::stoi(valueString));
				}
			}
			if (activeString == "height")
			{
				if (!checkInt(valueString))
				{
					return false;
				}
				else
				{
					form.labels[form.labels.size() - 1].text.setHeight(std::stoi(valueString));
				}
			}
			if (activeString == "italic")
			{
				if (checkBool(valueString))
				{
					if (getBool(valueString))
					{
						form.labels[form.labels.size() - 1].text.setItalic(true);
					}
					else
					{
						form.labels[form.labels.size() - 1].text.setItalic(false);
					}
				}
				else
				{
					return false;
				}
			}
			if (activeString == "underline")
			{
				if (checkBool(valueString))
				{
					if (getBool(valueString))
					{
						form.labels[form.labels.size() - 1].text.setUnderline(true);
					}
					else
					{
						form.labels[form.labels.size() - 1].text.setUnderline(false);
					}
				}
				else
				{
					return false;
				}
			}
			if (activeString == "bold")
			{
				if (checkBool(valueString))
				{
					if (getBool(valueString))
					{
						form.labels[form.labels.size() - 1].text.setBold(true);
					}
					else
					{
						form.labels[form.labels.size() - 1].text.setBold(false);
					}
				}
				else
				{
					return false;
				}
			}
			if (activeString == "title")
			{
				if (checkTitle(valueString))
				{
					form.labels[form.labels.size() - 1].text.setTitle(valueString);
				}
				else
				{
					return false;
				}
			}
		}


		if (scope.top() == NMWidgets::numberBox)
		{
			if (activeString == "text")
			{
				form.numberBoxes[form.numberBoxes.size() - 1].text.setText(valueString);
			}
			if (activeString == "positionVert")
			{
				if (!checkInt(valueString))
				{
					return false;
				}
				else
				{
					form.numberBoxes[form.numberBoxes.size() - 1].text.setPositionVert(std::stoi(valueString));
				}
			}
			if (activeString == "positionGorz")
			{
				if (!checkInt(valueString))
				{
					return false;
				}
				else
				{
					form.numberBoxes[form.numberBoxes.size() - 1].text.setPositionGorz(std::stoi(valueString));
				}
			}
			if (activeString == "height")
			{
				if (!checkInt(valueString))
				{
					return false;
				}
				else
				{
					form.numberBoxes[form.numberBoxes.size() - 1].text.setHeight(std::stoi(valueString));
				}
			}
			if (activeString == "italic")
			{
				if (checkBool(valueString))
				{
					if (getBool(valueString))
					{
						form.numberBoxes[form.numberBoxes.size() - 1].text.setItalic(true);
					}
					else
					{
						form.numberBoxes[form.numberBoxes.size() - 1].text.setItalic(false);
					}
				}
				else
				{
					return false;
				}
			}
			if (activeString == "underline")
			{
				if (checkBool(valueString))
				{
					if (getBool(valueString))
					{
						form.numberBoxes[form.numberBoxes.size() - 1].text.setUnderline(true);
					}
					else
					{
						form.numberBoxes[form.numberBoxes.size() - 1].text.setUnderline(false);
					}
				}
				else
				{
					return false;
				}
			}
			if (activeString == "bold")
			{
				if (checkBool(valueString))
				{
					if (getBool(valueString))
					{
						form.numberBoxes[form.numberBoxes.size() - 1].text.setBold(true);
					}
					else
					{
						form.numberBoxes[form.numberBoxes.size() - 1].text.setBold(false);
					}
				}
				else
				{
					return false;
				}
			}
			if (activeString == "title")
			{
				if (checkTitle(valueString))
				{
					form.numberBoxes[form.numberBoxes.size() - 1].text.setTitle(valueString);
				}
				else
				{
					return false;
				}
			}
		}




		if (scope.top() == NMWidgets::checkBox)
		{
			if (activeString == "text")
			{
				form.checkBoxes[form.checkBoxes.size() - 1].text.setText(valueString);
			}
			if (activeString == "positionVert")
			{
				if (!checkInt(valueString))
				{
					return false;
				}
				else
				{
					form.checkBoxes[form.checkBoxes.size() - 1].text.setPositionVert(std::stoi(valueString));
				}
			}
			if (activeString == "positionGorz")
			{
				if (!checkInt(valueString))
				{
					return false;
				}
				else
				{
					form.checkBoxes[form.checkBoxes.size() - 1].text.setPositionGorz(std::stoi(valueString));
				}
			}
			if (activeString == "height")
			{
				if (!checkInt(valueString))
				{
					return false;
				}
				else
				{
					form.checkBoxes[form.checkBoxes.size() - 1].text.setHeight(std::stoi(valueString));
				}
			}
			if (activeString == "italic")
			{
				if (checkBool(valueString))
				{
					if (getBool(valueString))
					{
						form.checkBoxes[form.checkBoxes.size() - 1].text.setItalic(true);
					}
					else
					{
						form.checkBoxes[form.checkBoxes.size() - 1].text.setItalic(false);
					}
				}
				else
				{
					return false;
				}
			}
			if (activeString == "underline")
			{
				if (checkBool(valueString))
				{
					if (getBool(valueString))
					{
						form.checkBoxes[form.checkBoxes.size() - 1].text.setUnderline(true);
					}
					else
					{
						form.checkBoxes[form.checkBoxes.size() - 1].text.setUnderline(false);
					}
				}
				else
				{
					return false;
				}
			}
			if (activeString == "bold")
			{
				if (checkBool(valueString))
				{
					if (getBool(valueString))
					{
						form.checkBoxes[form.checkBoxes.size() - 1].text.setBold(true);
					}
					else
					{
						form.checkBoxes[form.checkBoxes.size() - 1].text.setBold(false);
					}
				}
				else
				{
					return false;
				}
			}
			if (activeString == "title")
			{
				if (checkTitle(valueString))
				{
					form.checkBoxes[form.checkBoxes.size() - 1].text.setTitle(valueString);
				}
				else
				{
					return false;
				}
			}
		}




		if (scope.top() == NMWidgets::radioButton)
		{
			if (activeString == "text")
			{
				form.radioButtones[form.radioButtones.size() - 1].text.setText(valueString);
			}
			if (activeString == "positionVert")
			{
				if (!checkInt(valueString))
				{
					return false;
				}
				else
				{
					form.radioButtones[form.radioButtones.size() - 1].text.setPositionVert(std::stoi(valueString));
				}
			}
			if (activeString == "positionGorz")
			{
				if (!checkInt(valueString))
				{
					return false;
				}
				else
				{
					form.radioButtones[form.radioButtones.size() - 1].text.setPositionGorz(std::stoi(valueString));
				}
			}
			if (activeString == "height")
			{
				if (!checkInt(valueString))
				{
					return false;
				}
				else
				{
					form.radioButtones[form.radioButtones.size() - 1].text.setHeight(std::stoi(valueString));
				}
			}
			if (activeString == "italic")
			{
				if (checkBool(valueString))
				{
					if (getBool(valueString))
					{
						form.radioButtones[form.radioButtones.size() - 1].text.setItalic(true);
					}
					else
					{
						form.radioButtones[form.radioButtones.size() - 1].text.setItalic(false);
					}
				}
				else
				{
					return false;
				}
			}
			if (activeString == "underline")
			{
				if (checkBool(valueString))
				{
					if (getBool(valueString))
					{
						form.radioButtones[form.radioButtones.size() - 1].text.setUnderline(true);
					}
					else
					{
						form.radioButtones[form.radioButtones.size() - 1].text.setUnderline(false);
					}
				}
				else
				{
					return false;
				}
			}
			if (activeString == "bold")
			{
				if (checkBool(valueString))
				{
					if (getBool(valueString))
					{
						form.radioButtones[form.radioButtones.size() - 1].text.setBold(true);
					}
					else
					{
						form.radioButtones[form.radioButtones.size() - 1].text.setBold(false);
					}
				}
				else
				{
					return false;
				}
			}
			if (activeString == "title")
			{
				if (checkTitle(valueString))
				{
					form.radioButtones[form.radioButtones.size() - 1].text.setTitle(valueString);
				}
				else
				{
					return false;
				}
			}
		}



		if (scope.top() == NMWidgets::editLine)
		{
			if (activeString == "text")
			{
				form.editLines[form.editLines.size() - 1].text.setText(valueString);
			}
			if (activeString == "positionVert")
			{
				if (!checkInt(valueString))
				{
					return false;
				}
				else
				{
					form.editLines[form.editLines.size() - 1].text.setPositionVert(std::stoi(valueString));
				}
			}
			if (activeString == "positionGorz")
			{
				if (!checkInt(valueString))
				{
					return false;
				}
				else
				{
					form.editLines[form.editLines.size() - 1].text.setPositionGorz(std::stoi(valueString));
				}
			}
			if (activeString == "height")
			{
				if (!checkInt(valueString))
				{
					return false;
				}
				else
				{
					form.editLines[form.editLines.size() - 1].text.setHeight(std::stoi(valueString));
				}
			}
			if (activeString == "italic")
			{
				if (checkBool(valueString))
				{
					if (getBool(valueString))
					{
						form.editLines[form.editLines.size() - 1].text.setItalic(true);
					}
					else
					{
						form.editLines[form.editLines.size() - 1].text.setItalic(false);
					}
				}
				else
				{
					return false;
				}
			}
			if (activeString == "underline")
			{
				if (checkBool(valueString))
				{
					if (getBool(valueString))
					{
						form.editLines[form.editLines.size() - 1].text.setUnderline(true);
					}
					else
					{
						form.editLines[form.editLines.size() - 1].text.setUnderline(false);
					}
				}
				else
				{
					return false;
				}
			}
			if (activeString == "bold")
			{
				if (checkBool(valueString))
				{
					if (getBool(valueString))
					{
						form.editLines[form.editLines.size() - 1].text.setBold(true);
					}
					else
					{
						form.editLines[form.editLines.size() - 1].text.setBold(false);
					}
				}
				else
				{
					return false;
				}
			}
			if (activeString == "title")
			{
				if (checkTitle(valueString))
				{
					form.editLines[form.editLines.size() - 1].text.setTitle(valueString);
				}
				else
				{
					return false;
				}
			}

		}
		scope.push(NMWidgets::text);
	}





	else if (scope.top() == NMWidgets::button)
	{
		if (activeString == "sizeVert")
		{
			if (!checkInt(valueString))
			{
				return false;
			}
			else
			{
				form.buttons[form.buttons.size() - 1].setSizeVert(std::stoi(valueString));
			}
		}
		if (activeString == "sizeGorz")
		{
			if (!checkInt(valueString))
			{
				return false;
			}
			else
			{
				form.buttons[form.buttons.size() - 1].setSizeGorz(std::stoi(valueString));
			}
		}
		if (activeString == "positionVert")
		{
			if (!checkInt(valueString))
			{
				return false;
			}
			else
			{
				form.buttons[form.buttons.size() - 1].setPositionVert(std::stoi(valueString));
			}
		}
		if (activeString == "positionGorz")
		{
			if (!checkInt(valueString))
			{
				return false;
			}
			else
			{
				form.buttons[form.buttons.size() - 1].setPositionGorz(std::stoi(valueString));
			}
		}
		if (activeString == "clicable")
		{
			if (checkBool(valueString))
			{
				if (getBool(valueString))
				{
					form.buttons[form.buttons.size() - 1].setClicable(true);
				}
				else
				{
					form.buttons[form.buttons.size() - 1].setClicable(false);
				}
			}
			else
			{
				return false;
			}
		}
		if (activeString == "doubleClicable")
		{
			if (checkBool(valueString))
			{
				if (getBool(valueString))
				{
					form.buttons[form.buttons.size() - 1].setDoubleClicable(true);
				}
				else
				{
					form.buttons[form.buttons.size() - 1].setDoubleClicable(false);
				}
			}
			else
			{
				return false;
			}
		}
		if (activeString == "name")
		{
			form.buttons[form.buttons.size() - 1].setName(valueString);
		}
	}






	else if (scope.top() == NMWidgets::label)
	{
		if (activeString == "positionVert")
		{
			if (!checkInt(valueString))
			{
				return false;
			}
			else
			{
				form.labels[form.labels.size() - 1].setPositionVert(std::stoi(valueString));
			}
		}
		if (activeString == "positionGorz")
		{
			if (!checkInt(valueString))
			{
				return false;
			}
			else
			{
				form.labels[form.labels.size() - 1].setPositionGorz(std::stoi(valueString));
			}
		}
		if (activeString == "name")
		{
			form.labels[form.labels.size() - 1].setName(valueString);
		}
	}




	else if (scope.top() == NMWidgets::numberBox)
	{
		if (activeString == "positionVert")
		{
			if (!checkInt(valueString))
			{
				return false;
			}
			else
			{
				form.numberBoxes[form.numberBoxes.size() - 1].setPositionVert(std::stoi(valueString));
			}
		}
		if (activeString == "positionGorz")
		{
			if (!checkInt(valueString))
			{
				return false;
			}
			else
			{
				form.numberBoxes[form.numberBoxes.size() - 1].setPositionGorz(std::stoi(valueString));
			}
		}
		if (activeString == "name")
		{
			form.numberBoxes[form.numberBoxes.size() - 1].setName(valueString);
		}
		if (activeString == "minValue")
		{
			if (!checkInt(valueString))
			{
				return false;
			}
			else
			{
				form.numberBoxes[form.numberBoxes.size() - 1].setMinValue(std::stoi(valueString));
			}
		}
		if (activeString == "maxValue")
		{
			if (!checkInt(valueString))
			{
				return false;
			}
			else
			{
				form.numberBoxes[form.numberBoxes.size() - 1].setMaxValue(std::stoi(valueString));
			}
		}
		if (activeString == "defaultValue")
		{
			if (!checkInt(valueString))
			{
				return false;
			}
			else
			{
				form.numberBoxes[form.numberBoxes.size() - 1].setDefaultValue(std::stoi(valueString));
			}
		}
		if (activeString == "clicable")
		{
			if (checkBool(valueString))
			{
				if (getBool(valueString))
				{
					form.numberBoxes[form.numberBoxes.size() - 1].setClicable(true);
				}
				else
				{
					form.numberBoxes[form.numberBoxes.size() - 1].setClicable(false);
				}
			}
			else
			{
				return false;
			}
		}
	}



	else if (scope.top() == NMWidgets::checkBox)
	{
		if (activeString == "positionVert")
		{
			if (!checkInt(valueString))
			{
				return false;
			}
			else
			{
				form.checkBoxes[form.checkBoxes.size() - 1].setPositionVert(std::stoi(valueString));
			}
		}
		if (activeString == "positionGorz")
		{
			if (!checkInt(valueString))
			{
				return false;
			}
			else
			{
				form.checkBoxes[form.checkBoxes.size() - 1].setPositionGorz(std::stoi(valueString));
			}
		}
		if (activeString == "name")
		{
			form.checkBoxes[form.checkBoxes.size() - 1].setName(valueString);
		}
		if (activeString == "defaultValue")
		{
			if (checkBool(valueString))
			{
				if (getBool(valueString))
				{
					form.checkBoxes[form.checkBoxes.size() - 1].setDefaultValue(true);
				}
				else
				{
					form.checkBoxes[form.checkBoxes.size() - 1].setDefaultValue(false);
				}
			}
		}
		if (activeString == "clicable")
		{
			if (checkBool(valueString))
			{
				if (getBool(valueString))
				{
					form.checkBoxes[form.checkBoxes.size() - 1].setClicable(true);
				}
				else
				{
					form.checkBoxes[form.checkBoxes.size() - 1].setClicable(false);
				}
			}
			else
			{
				return false;
			}
		}
	}


	else if (scope.top() == NMWidgets::radioButton)
	{
		if (activeString == "positionVert")
		{
			if (!checkInt(valueString))
			{
				return false;
			}
			else
			{
				form.radioButtones[form.radioButtones.size() - 1].setPositionVert(std::stoi(valueString));
			}
		}
		if (activeString == "positionGorz")
		{
			if (!checkInt(valueString))
			{
				return false;
			}
			else
			{
				form.radioButtones[form.radioButtones.size() - 1].setPositionGorz(std::stoi(valueString));
			}
		}
		if (activeString == "name")
		{
			form.radioButtones[form.radioButtones.size() - 1].setName(valueString);
		}
		if (activeString == "groupName")
		{
			form.radioButtones[form.radioButtones.size() - 1].setGroupName(valueString);
		}
		if (activeString == "defaultValue")
		{
			if (checkBool(valueString))
			{
				if (getBool(valueString))
				{
					form.radioButtones[form.radioButtones.size() - 1].setDefaultValue(true);
				}
				else
				{
					form.radioButtones[form.radioButtones.size() - 1].setDefaultValue(false);
				}
			}
		}
	}




	else if (scope.top() == NMWidgets::button)
	{
		if (activeString == "sizeVert")
		{
			if (!checkInt(valueString))
			{
				return false;
			}
			else
			{
				form.buttons[form.buttons.size() - 1].setSizeVert(std::stoi(valueString));
			}
		}
		if (activeString == "sizeGorz")
		{
			if (!checkInt(valueString))
			{
				return false;
			}
			else
			{
				form.buttons[form.buttons.size() - 1].setSizeGorz(std::stoi(valueString));
			}
		}
		if (activeString == "positionVert")
		{
			if (!checkInt(valueString))
			{
				return false;
			}
			else
			{
				form.buttons[form.buttons.size() - 1].setPositionVert(std::stoi(valueString));
			}
		}
		if (activeString == "positionGorz")
		{
			if (!checkInt(valueString))
			{
				return false;
			}
			else
			{
				form.buttons[form.buttons.size() - 1].setPositionGorz(std::stoi(valueString));
			}
		}
		if (activeString == "clicable")
		{
			if (checkBool(valueString))
			{
				if (getBool(valueString))
				{
					form.buttons[form.buttons.size() - 1].setClicable(true);
				}
				else
				{
					form.buttons[form.buttons.size() - 1].setClicable(false);
				}
			}
			else
			{
				return false;
			}
		}
		if (activeString == "doubleClicable")
		{
			if (checkBool(valueString))
			{
				if (getBool(valueString))
				{
					form.buttons[form.buttons.size() - 1].setDoubleClicable(true);
				}
				else
				{
					form.buttons[form.buttons.size() - 1].setDoubleClicable(false);
				}
			}
			else
			{
				return false;
			}
		}
		if (activeString == "name")
		{
			form.buttons[form.buttons.size() - 1].setName(valueString);
		}
	}



	else if (scope.top() == NMWidgets::form)
	{
		if (activeString == "sizeVert")
		{
			if (!checkInt(valueString))
			{
				return false;
			}
			else
			{
				form.setSizeVert(std::stoi(valueString));
			}
		}
		if (activeString == "sizeGorz")
		{
			if (!checkInt(valueString))
			{
				return false;
			}
			else
			{
				form.setSizeGorz(std::stoi(valueString));
			}
		}
		if (activeString == "name")
		{
			form.setName(valueString);
		}
	}


	bool closeScope = false;
	for (size_t i = 0; i < parcingString.size(); ++i)
	{
		if (closeScope && (parcingString[i] != ']' || parcingString[i] != ' '))
		{
			return false;
		}
		if (parcingString[i] == ']')
		{
			closeScope = true;
		}

	}
	if (closeScope)
	{
		std::cout << "\nClose scope " << scope.top() << '\n';
		scope.pop();
	}
	
	return true;
}

bool Parcer::getWidget()
{
	activeString.clear();
	bool inScope = false;
	for (size_t i = 1; i < parcingString.size(); ++i)
	{
		if (parcingString[i] != '[' && parcingString[i] != ' '
			&& parcingString[i] != '|' && parcingString[i] != '/'
			&& parcingString[i] != '>' && parcingString[i] != '#')
		{
			activeString += parcingString[i];
		}

		if (parcingString[i] == '[')
		{
			inScope = true;
			break;
			//std::cout << '\n' << activeString << '\n';
		}
	}
	if (inScope != true || (activeString != NMWidgets::button && 
		activeString != NMWidgets::label && activeString != NMWidgets::text)
		&& activeString != NMWidgets::numberBox && activeString != NMWidgets::checkBox
		&& activeString != NMWidgets::radioButton && activeString != NMWidgets::editLine)
	{
		return false;
	}

	return true;
}

bool Parcer::getParam()
{
	activeString.clear();
	bool value = false;
	bool closeScope = false;
	for (size_t i = 1; i < parcingString.size(); ++i)
	{
		if (parcingString[i] == ':')
		{
			value = true;
			break;
			//std::cout << '\n' << activeString << '\n';
		}
		if (parcingString[i] == ']')
		{
			closeScope = true;
		}
		if (parcingString[i] != '[' && parcingString[i] != ' '
			&& parcingString[i] != '|' && parcingString[i] != '/'
			&& parcingString[i] != '>' && parcingString[i] != '#')
		{
			activeString += parcingString[i];
		}
	}
	if (value != true)
	{
		if (closeScope)
		{
			onlyScope = true;
		}
		else
		{
			return false;
		}
		
	}

	return true;
}

bool Parcer::getValue()
{
	valueString.clear();
	bool value = false;
	bool firstspace = false;
	for (size_t i = 1; i < parcingString.size(); ++i)
	{

		if (value)
		{
			if (parcingString[i] != '[' && parcingString[i] != ']'
				&& parcingString[i] != '|' && parcingString[i] != '/'
				&& parcingString[i] != '>' && parcingString[i] != '#')
			{
				if (parcingString[i] != ' ' || firstspace)
				{
					valueString += parcingString[i];
				}
				if (parcingString[i] == ' ')
				{
					firstspace = true;
				}
			}

		}
		if (parcingString[i] == ':')
		{
			value = true;
		}
	}
	if (valueString.size() == 0)
	{
		if (onlyScope)
		{

		}
		else
		{
			return false;
		}
		
	}

	return true;
}

bool Parcer::checkParam()
{
	if (onlyScope)
	{

	}
	else
	{
		if (scope.top() == NMWidgets::text)
		{
			if (activeString != "text"
				&& activeString != "positionVert" && activeString != "positionGorz"
				&& activeString != "height" && activeString != "italic"
				&& activeString != "underline" && activeString != "bold"
				&& activeString != "title")
			{
				return false;
			}
		}
		else if (scope.top() == NMWidgets::button)
		{
			if (activeString != "sizeVert" && activeString != "sizeGorz"
				&& activeString != "positionVert" && activeString != "positionGorz"
				&& activeString != "name" && activeString != "clicable" && activeString != "doubleClicable")
			{
				return false;
			}
		}
		else if (scope.top() == NMWidgets::label)
		{
			if (activeString != "positionVert" && activeString != "positionGorz"
				&& activeString != "name")
			{
				return false;
			}
		}
		else if (scope.top() == NMWidgets::numberBox)
		{
			if (activeString != "positionVert" && activeString != "positionGorz"
				&& activeString != "name" && activeString != "minValue" && activeString != "maxValue"
				&& activeString != "defaultValue" && activeString != "clicable")
			{
				return false;
			}
		}
		else if (scope.top() == NMWidgets::checkBox)
		{
			if (activeString != "positionVert" && activeString != "positionGorz"
				&& activeString != "name" && activeString != "defaultValue"
				&& activeString != "clicable")
			{
				return false;
			}
		}
		else if (scope.top() == NMWidgets::radioButton)
		{
			if (activeString != "positionVert" && activeString != "positionGorz"
				&& activeString != "name" && activeString != "defaultValue"
				&& activeString != "groupName")
			{
				return false;
			}
		}
		else if (scope.top() == NMWidgets::editLine)
		{
			if (activeString != "sizeVert" && activeString != "sizeGorz"
				&& activeString != "positionVert" && activeString != "positionGorz"
				&& activeString != "name" && activeString != "multiline")
			{
				return false;
			}
		}
		else if (scope.top() == NMWidgets::form)
		{
			if (activeString != "sizeVert" && activeString != "sizeGorz" && activeString != "name")
			{
				return false;
			}
		}
		return true;
	}
	
}


