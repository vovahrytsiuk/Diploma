#pragma once
#include <iostream>
#include "Text.h"
class CheckBox
{
public:
	CheckBox();
	~CheckBox() = default;


	void setPositionVert(int info);
	int  getPositionVert();
	void setPositionGorz(int info);
	int  getPositionGorz();
	void setName(std::string info);
	std::string getName();
	void setDefaultValue(bool info);
	bool setDefaultValue();
	void setClicable(bool info);
	bool getClicable();

	Text text;

private:
	std::string name;
	int positionVert = 0;
	int positionGorz = 0;
	bool defaultValue = false;
	bool clicable = false;

};

