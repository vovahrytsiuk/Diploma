#pragma once
#include <iostream>
#include "Text.h"
class Label
{
public:
	Label();
	~Label() = default;


	void setPositionVert(int info);
	int  getPositionVert();
	void setPositionGorz(int info);
	int  getPositionGorz();
	void setName(std::string info);
	std::string getName();

	Text text;

private:
	std::string name;
	int positionVert = 0;
	int positionGorz = 0;
	
};

