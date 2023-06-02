#pragma once
#include <iostream>
#include "Text.h"
class RadioButton
{
public:
	RadioButton();
	~RadioButton() = default;


	void setPositionVert(int info);
	int  getPositionVert();
	void setPositionGorz(int info);
	int  getPositionGorz();
	void setName(std::string info);
	std::string getName();
	void setDefaultValue(bool info);
	bool setDefaultValue();
	void setGroupName(std::string info);
	std::string getGroupName();

	Text text;
private:
	std::string name;
	std::string groupName = "RB";
	int positionVert = 0;
	int positionGorz = 0;
	bool defaultValue = false;


};

