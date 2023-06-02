#include "Label.h"
#include <stdlib.h>
#include <time.h>
#include <string>

Label::Label()
{
	srand(time(NULL));
	name = std::to_string(rand());
}

void Label::setPositionVert(int info)
{
	positionVert = info;
	std::cout << "Set positionVert: " << info << " for " << name << '\n';
}

int Label::getPositionVert()
{
	return positionVert;
}

void Label::setPositionGorz(int info)
{
	positionGorz = info;
	std::cout << "Set positionGorz: " << info << " for " << name << '\n';
}

int Label::getPositionGorz()
{
	return positionGorz;
}

void Label::setName(std::string info)
{
	name = info;
	std::cout << "Set name: " << info << " for " << name << '\n';
}

std::string Label::getName()
{
	return name;
}
