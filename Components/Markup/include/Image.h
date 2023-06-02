#pragma once
#include <iostream>
#include "Text.h"
class Image
{
public:
	Image();
	~Image() = default;


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
	void setPath(std::string info);
	std::string getPath();


private:
	std::string path = "";
	std::string name;
	int sizeVert = 72;
	int sizeGorz = 120;
	int positionVert = 0;
	int positionGorz = 0;
\
};

