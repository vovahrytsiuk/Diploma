#pragma once
#include <iostream>
#include "Text.h"
class Button
{
public:
	Button();
	~Button() = default;


	void setSizeVert(int info);
	int  getSizeVert();
	void setSizeGorz(int info);
	int  getSizeGorz();
	void setPositionVert(int info);
	int  getPositionVert();
	void setPositionGorz(int info);
	int  getPositionGorz();
	void setName(std::string info);
	std::string getName();
	void setClicable(bool info);
	bool getClicable();
	void setDoubleClicable(bool info);
	bool getDoubleClicable();


	Text text;
private:
	std::string name;
	int sizeVert = 72;
	int sizeGorz = 120;
	int positionVert = 0;
	int positionGorz = 0;
	
	bool clicable = false;
	bool doubleClicable = false;
};

