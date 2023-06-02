#pragma once
#pragma once
#include <iostream>
#include "Text.h"
class NumberBox
{
public:
	NumberBox();
	~NumberBox() = default;


	void setPositionVert(int info);
	int  getPositionVert();
	void setPositionGorz(int info);
	int  getPositionGorz();
	void setName(std::string info);
	std::string getName();
	void setMinValue(int info);
	int setMinValue();
	void setMaxValue(int info);
	int setMaxValue();
	void setDefaultValue(int info);
	int setDefaultValue();
	void setClicable(bool info);
	bool getClicable();

	Text text;

private:
	std::string name;
	int positionVert = 0;
	int positionGorz = 0;
	int minValue = 0;
	int maxValue = 12;
	int defaultValue = 0;
	bool clicable = false;

};
